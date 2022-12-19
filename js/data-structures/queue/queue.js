class Queue {
    constructor() {
        this.data = [];
        this.head = -1;
        this.tail = -1;
    }

    /**
     * @return {boolean}
     */
    isEmpty() {
        return (this.head === 0);
    }

    /**
     * @returns {number}
     */
    size() {
        return this.tail - this.head;
    }

    /**
     * 
     * @param {number} key
     * @returns {void}
     */
    queue(key) {
        this.tail++;
        this.data[this.tail] = key;
    }

    /**
     * @returns {number}
     */
    dequeue() {
        if (this.isEmpty()) {
            return undefined;
        }

        let item = this.data[this.head];
        delete this.data[this.head];
        this.head++;

        return item;
    }

}

export {Queue};