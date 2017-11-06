// LinkedList ADT which stores objects

@SuppressWarnings("overrides")
class List {
    private class Node {
        Object data;
        Node next, prev;

        Node(Object data) { this.data = data; next = prev = null; }

        public String toString() { return data.toString(); }
    }
    private Node front, back, cursor;
    private int length;
    private int index;

    List() { front = back = null; index = -1; }

    public int length() { return length; }
    public int index() {
        if (cursor == null) index = -1;
        return index;
    }
    public Object front() {
        if (length() == 0) throw new RuntimeException("List Error: front() called on empty List");
        return front.data;
    }
    public Object back() {
        if (length() == 0) throw new RuntimeException("List Error: back() called on empty List");
        return back.data;
    }
    public Object get() {
        if (length() == 0 || index() == -1) throw new RuntimeException("List Error: get() called List which is empty or has no cursor");
        return cursor.data;
    }
    public boolean equals(Object x) {
        if (x == this) return true;
        if (x == null || x.getClass() != getClass()) return false;
        List L = (List) x;
        Node N = front;
        Node M = L.front;
        while (N != null && M != null && N.data.equals(M.data)) {
            N = N.next;
            M = M.next;
        }
        return N == M;
    }

    public void clear() {
        front = back = cursor = null;
        length = 0;
        index = -1;
    }
    public void moveFront() {
        if (length() > 0) cursor = front;
        index = 0;
    }
    public void moveBack() {
        if (length() > 0) cursor = back;
        index = length - 1;
    }
    public void movePrev() {
        if (cursor != null) cursor = cursor.prev;
        index--;
    }
    public void moveNext() {
        if (cursor != null) cursor = cursor.next;
        index++;
    }
    public void prepend(Object data) {
        Node N = new Node(data);
        if (length == 0) front = back = N;
        else {
            front.prev = N;
            N.next = front;
            front = N;
        }
        length++;
        index++;
    }
    public void append(Object data) {
        Node N = new Node(data);
        if (length == 0) front = back = N;
        else {
            back.next = N;
            N.prev = back;
            back = N;
        }
        length++;
    }
    public void insertBefore(Object data) {
        if (length() == 0 || index() == -1) throw new RuntimeException("List Error: insertBefore() called List which is empty or has no cursor");
        Node N = new Node(data);
        if (cursor == front) front = N;
        else {
            Node H = cursor.prev;
            N.prev = H;
            H.next = N;
        }
        N.next = cursor;
        cursor.prev = N;
        length++;
        index++;
    }
    public void insertAfter(Object data) {
        if (length() == 0 || index() == -1) throw new RuntimeException("List Error: insertAfter() called List which is empty or has no cursor");
        Node N = new Node(data);
        if (cursor == back) back = N;
        else {
            Node H = cursor.next;
            N.next = H;
            H.prev = N;
        }
        N.prev = cursor;
        cursor.next = N;
        length++;        
    }
    public void deleteFront() {
        if (length() == 0) throw new RuntimeException("List Error: deleteFront() called on empty List");
        Node N = front.next;
        if (cursor == front) cursor = null;
        front = N;
        if (N != null) N.prev = null;
        length--;
    }
    public void deleteBack() {
        if (length() == 0) throw new RuntimeException("List Error: deleteBack() called on empty List");
        Node N = back.prev;
        if (cursor == back) cursor = null;
        back = N;
        if (N != null) N.next = null;
        length--;
    }
    public void delete() {
        if (length == 0 || cursor == null) throw new RuntimeException("List Error: delete() called List which is empty or has no cursor");
        Node N = cursor.next;
        Node P = cursor.prev;
        if (cursor == front) front = N;
        else if (cursor == back) back = P;
        if (N != null) N.prev = P;
        if (P != null) P.next = N;
        cursor = null;
        length--;
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();
        if (front != null) {
            for (Node N = front; N.next != null; N = N.next)
                sb.append(N.toString() + " ");
            sb.append(back.toString());
        }
        return new String(sb);
    }
}