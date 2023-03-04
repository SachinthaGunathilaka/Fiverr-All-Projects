/*
 * Author: Rafi Rubin
 */
public abstract class Nestable {
    @SuppressWarnings("unused")
    private static final long serialVersionUID = 1094891280812308L;

    public enum NestEffect {
        OPEN, NEUTRAL, CLOSE
    }

    public NestEffect effect;

    public abstract boolean matches(Nestable other);

    public NestEffect getEffect() {
        return effect;
    }

    public NestEffect getInverseEffect() {
        switch (effect) {
            case OPEN:
                return NestEffect.CLOSE;
            case CLOSE:
                return NestEffect.OPEN;
            case NEUTRAL:
                return NestEffect.NEUTRAL;
        }
        return NestEffect.NEUTRAL;
    }
}
