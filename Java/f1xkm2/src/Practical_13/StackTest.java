package Practical_13;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class StackTest {

    private Stack stack;


    @org.junit.jupiter.api.BeforeEach
    public void init() {
        stack = new Stack();
    }

    @Test
    void testStack() {
        stack.push("10");
        stack.push("20");
        stack.push("+");
        stack.push("/");
        stack.push("5");

        assertEquals("5", stack.pop());
        assertEquals("(10,20,+,/)", stack.getContent().toString());
        assertEquals("/", stack.pop());
        assertEquals("(10,20,+)", stack.getContent().toString());
        assertEquals("+", stack.pop());
        assertEquals("20", stack.pop());
        assertEquals("(10)", stack.getContent().toString());

    }

}