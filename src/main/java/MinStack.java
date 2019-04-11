import java.util.Stack;

public class MinStack {
    Stack<Integer> s1, s2;
    int min;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        s1 = new Stack<Integer>();
        s2 = new Stack<Integer>();
        min = Integer.MAX_VALUE;
    }

    public void push(int x) {
        s1.push(x);
        min = Math.min(min, x);
        s2.push(min);
    }

    public void pop() {
        s1.pop();
        s2.pop();
        if (!s2.empty())
            min = s2.peek();
        else
            min = Integer.MAX_VALUE;
    }

    public int top() {
        return s1.peek();
    }

    public int getMin() {
        return min;
    }
}