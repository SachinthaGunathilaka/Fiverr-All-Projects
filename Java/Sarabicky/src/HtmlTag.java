/*
 * Author: CIT 594 course staff
 */

import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/*
 * Instructor-provided code. Do not change!
 */
public class HtmlTag extends Nestable {
    private static final long serialVersionUID = 92846583918347L;

    protected final String element;

    public HtmlTag(String element, NestEffect effect) {
        this.element = element.toLowerCase();
        this.effect = effect;
    }

    public HtmlTag(String element, boolean opening) {
        this.element = element;
        if (SELF_CLOSING_TAGS.contains(element))
            effect = NestEffect.NEUTRAL;
        else
            effect = opening ? NestEffect.OPEN : NestEffect.CLOSE;
    }

    public String getElement() {
        return element;
    }

    public boolean matches(Nestable other) {
        if (other instanceof HtmlTag) {
            HtmlTag nother = (HtmlTag) other;
            return element.equals(nother.element) && getEffect() == nother.getInverseEffect();
        }
        return false;
    }

    public boolean equals(Object obj) {
        if (obj instanceof HtmlTag) {
            HtmlTag other = (HtmlTag) obj;
            return element.equals(other.element) && effect == other.effect;
        }
        return false;
    }

    public String toString() {
        return (effect == NestEffect.CLOSE ? "</" : "<") + (element.equals("!--") ? "!-- --" : element)
                + (effect == NestEffect.NEUTRAL ? "/>" : ">");
    }

    /**
     * The remaining fields and functions are related to HTML file parsing.
     */

    // a set of tags that don't need to be matched (self-closing)
    // https://html.spec.whatwg.org/multipage/syntax.html#void-elements
    protected static final Set<String> SELF_CLOSING_TAGS = new HashSet<String>(
            Arrays.asList("!doctype", "!--", "?xml", "xml", "area", "base", "basefont", "br", "col", "embed", "frame",
                    "hr", "img", "input", "link", "meta", "param", "source", "track", "wbr"));

    protected static final String WHITESPACE = " \f\n\r\t";

    public static Queue<HtmlTag> tokenize(String text) {
        StringBuilder buf = new StringBuilder(text);
        Queue<HtmlTag> queue = new LinkedList<HtmlTag>();

        HtmlTag nextTag = nextTag(buf);
        while (nextTag != null) {
            queue.add(nextTag);
            nextTag = nextTag(buf);
        }
        return queue;
    }

    protected static HtmlTag nextTag(StringBuilder buf) {
        int openBracket = buf.indexOf("<");
        int closeBracket = buf.indexOf(">");
        boolean isComment = false;
        if (openBracket >= 0 && closeBracket > openBracket) {
            // check for HTML comments: <!-- -->
            int commentIndex = openBracket + 4;
            if (commentIndex <= buf.length() && buf.substring(openBracket + 1, commentIndex).equals("!--")) {
                // look for closing comment tag -->
                closeBracket = buf.indexOf("-->", commentIndex);
                if (closeBracket < 0) {
                    return null;
                } else {
                    closeBracket += 3; // advance to the closing bracket >
                    isComment = true;
                }
            }

            if (isComment) {
                buf.delete(0, closeBracket + 1);
                return new HtmlTag("!--", NestEffect.NEUTRAL);
            }

            NestEffect effect = NestEffect.OPEN;
            String element = buf.substring(openBracket + 1, closeBracket);
            buf.delete(0, closeBracket + 1);

            if (element.startsWith("/")) {
                effect = NestEffect.CLOSE;
                element = element.substring(1);
            } else if (element.endsWith("/")) {
                effect = NestEffect.NEUTRAL;
                element = element.substring(0, element.length() - 1);
            }
            element = element.trim();

            // remove attributes
            for (int i = 0; i < WHITESPACE.length(); i++) {
                int elStart = 0;
                int attributeIndex = 0;
                while ((attributeIndex = element.indexOf(WHITESPACE.charAt(i), elStart)) == elStart)
                    elStart++;
                if (attributeIndex > 0) {
                    element = element.substring(elStart, attributeIndex);
                } else if (elStart > 0)
                    element = element.substring(elStart);
            }

            element = element.replaceAll("[^a-zA-Z0-9!-]+", "");

            // Note </br> for example could be closing at this point and should be NEUTRAL
            if (SELF_CLOSING_TAGS.contains(element)) {
                effect = NestEffect.NEUTRAL;
            }
            return new HtmlTag(element, effect);
        }
        return null;
    }
}
