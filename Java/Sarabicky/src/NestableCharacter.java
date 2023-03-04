import java.util.HashMap;
import java.util.Map;

public class NestableCharacter extends Nestable {
    @SuppressWarnings("unused")
    private static final long serialVersionUID = 184829238437L;

    public static char[][] syntaxPairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    public static Map<Character, Character> mSyntaxPairs = new HashMap<>();
    public static Map<Character, NestEffect> charType = new HashMap<>();

    /*
     * populate the lookup tables for pairing and effects
     */
    static {
        for (char[] pair : syntaxPairs) {
            charType.put(pair[0], NestEffect.OPEN);
            charType.put(pair[1], NestEffect.CLOSE);
            mSyntaxPairs.put(pair[0], pair[1]);
            mSyntaxPairs.put(pair[1], pair[0]);
        }
    }

    Character value;

    public NestableCharacter(char c) {
        value = c;
        effect = charType.getOrDefault(value, NestEffect.NEUTRAL);
    }

    public NestableCharacter(int i) {
        this((char) i);
    }

    public boolean matches(NestableCharacter other) {
        if (getEffect() == other.getInverseEffect())
            return value.equals(mSyntaxPairs.get(other.value));
        return false;
    }

    @Override
    public boolean matches(Nestable other) {
        if (other == null || !(other instanceof NestableCharacter) || (getEffect() != other.getInverseEffect()))
            return false;

        NestableCharacter ncOther = (NestableCharacter) other;
        if (value == null)
            return ncOther.value == null;
        return value.equals(mSyntaxPairs.get(ncOther.value));
    }

    @Override
    public boolean equals(Object other) {
        if ((other == null) || !(other instanceof NestableCharacter))
            return false;
        NestableCharacter oc = (NestableCharacter) other;
        if (value == null)
            return oc.value == null;
        else
            return value.equals(oc.value);
    }

    public int hashCode() {
        return value.hashCode();
    }

    public String toString() {
        return "'" + value + "':" + effect;
    }
}
