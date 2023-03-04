import java.util.Objects;

public class Sentence implements Comparable<Sentence> {
	protected int score;
	protected String text;
	
	public Sentence(int score, String text) {
		this.score = score;
		this.text = text;
	}
	
	public int getScore() {
		return score;
	}
	
	public String getText() {
		return text;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!(o instanceof Sentence)) return false;
		Sentence sentence = (Sentence) o;
		return score == sentence.score && Objects.equals(text, sentence.text);
	}

	@Override
	public int compareTo(Sentence o) {
		return this.score - o.score;
	}
}
