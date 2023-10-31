class Array<T> {
  
  private Object[] elements;
  private int quantity;
  public int length;

  public Array(int length) {
    this.elements = new Object[length];
    this.length = length;
    this.quantity = 0;
  }

  public T get(int index) throws IllegalIndexException {
    validateIndex(index);

    return (T) elements[index];
  }

  public void add(T element) throws FullArrayException {
    validateFullArray();

    elements[quantity] = element;
    quantity++;
  }

  public void insert(T element, int index) throws FullArrayException, IllegalIndexException {
    validateIndex(index);
    validateFullArray();

    if (index > quantity + 1) throw new IllegalIndexException();

    elements[index] = element;
  }

  public void remove(T element) throws EmptyArrayException, ElementNotFoundException {
    validateEmptyArray();

    try {
      int position = search(element);

      for (int i = position; i < quantity; i++) {
        elements[i] = elements[i + 1];
      }

      elements[quantity - 1] = null;
      quantity--;
    } catch (ElementNotFoundException exception) {
      throw exception;
    }
  }

  public int search(T element) throws ElementNotFoundException, EmptyArrayException {
    validateEmptyArray();

    for (int i = 0; i < quantity; i++) {
      if (elements[i] == element)
        return i;
    }

    throw new ElementNotFoundException();
  }

  public void pop() throws IllegalIndexException, ElementNotFoundException, EmptyArrayException {
    remove(quantity - 1);
  }

  public void shift() throws IllegalIndexException, ElementNotFoundException, EmptyArrayException {
    remove(0);
  }

  public void print() {
    System.out.print("[ ");

    for (int i = 0; i < quantity; i++) {
      System.out.print(elements[i]);

      if (i < quantity - 1) System.out.print(", ");
    }

    System.out.println(" ]");
  }

  private void remove(int index) throws EmptyArrayException, ElementNotFoundException, IllegalIndexException {
    validateEmptyArray();
    validateIndex(index);

    for (int i = index; i < quantity; i++) {
      elements[i] = elements[i + 1];
    }

    elements[quantity - 1] = null;
    quantity--;
  }

  private void validateIndex(int index) throws IllegalIndexException {
    if (index < 0 || index >= length)
      throw new IllegalIndexException();
  }

  private void validateFullArray() throws FullArrayException {
    if (quantity >= length - 1)
      throw new FullArrayException();
  }

  private void validateEmptyArray() throws EmptyArrayException {
    if (quantity == 0)
      throw new EmptyArrayException();
  }
}
