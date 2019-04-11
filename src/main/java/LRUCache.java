import java.util.HashMap;

public class LRUCache {

    HashMap<Integer, DLinkedNode> map;
    int capacity;
    DLinkedNode head, tail;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        this.capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head.pre = null;
        head.next = tail;
        tail.pre = head;
        tail.next = null;
    }

    public static void main(String[] args) {
        LRUCache cache = new LRUCache(2);
        cache.put(2, 1);
        cache.put(1, 1);
        cache.put(2, 3);
        cache.put(4, 1);
        cache.get(1);
        cache.get(2);
    }

    public int get(int key) {
        DLinkedNode node = map.get(key);
        if (node == null)
            return -1;
        removeNode(node);
        addHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        DLinkedNode node = new DLinkedNode();
        node.key = key;
        node.value = value;
        if (map.containsKey(key)) {
            removeNode(map.get(key));
        } else if (map.size() == capacity) {
            int k = removeTail();
            map.remove(k);
        }
        addHead(node);
        map.put(key, node);
    }

    public void removeNode(DLinkedNode node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
        node.pre = null;
        node.next = null;
    }

    public int removeTail() {
        DLinkedNode node = tail.pre;
        removeNode(node);
        return node.key;
    }

    public void addHead(DLinkedNode node) {
        node.next = head.next;
        node.pre = head;
        node.next.pre = node;
        head.next = node;
    }

    class DLinkedNode {
        int key;
        int value;
        DLinkedNode pre;
        DLinkedNode next;
    }
}
