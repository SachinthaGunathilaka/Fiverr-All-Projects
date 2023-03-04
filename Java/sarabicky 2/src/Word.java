import java.util.Objects;

public class Word implements Comparable<Word> {
	protected String text;
	protected int count;
	protected int total;
	
	/*
	 * Note that this does not set the value or increment the counter.
	 * It just creates an object with no count and no total so far.
	 */
	public Word(String text) {
		this.text = text;
		count = 0;
		total = 0;
	}
	
	public void increaseTotal(int value) {
		total += value;
		count++;
	}
	
	public double calculateScore() {
		if (count == 0) {
			return 0;
		}
		return ((double) total) / count;
	}
	
	public int getCount() {
		return count;
	}
	
	public int getTotal() {
		return total;
	}
	
	public String getText() {
		return text;
	}
	
	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!(o instanceof Word)) return false;
		Word word = (Word) o;
		return count == word.count && total == word.total && Objects.equals(text, word.text);
	}

	@Override
	public int compareTo(Word o) {
		int cmp;
		if ((cmp = this.text.compareTo(o.text)) != 0) return cmp;
		if ((cmp = (this.count - o.count)) != 0) return cmp;
		return this.total - o.total;
	}

	@Override
	public int hashCode() {
		return Objects.hash(text, count, total);
	}

	@Override
	public String toString() {
		return "Word{" +
				"text='" + text + '\'' +
				", count=" + count +
				", total=" + total +
				'}';
	}
}
