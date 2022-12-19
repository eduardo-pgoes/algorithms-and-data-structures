class Stack {
    constructor() {
        this.data = [];
        this.top = -1;
    }

    /*
    *   Pushes an element into the array.
    *   @param {any} element - element to be pushed
    */
    push(element) {
        this.top++;
        this.data[this.top] = element;
    }

    /*
    *   Pops an element out of the stack.
    *   @return {element} data - element that has been popped
    */
    pop() {
        if (this.isEmpty != true) {
            this.top--;
            return this.data[this.top+1];
        }
    }

    /*
    *   Checks the stack emptiness status.
    *   @return {number} - 1 if the stack is empty, 0 otherwise
    */
    isEmpty() {
        return (this.top === -1);
    }
}

export {Stack};