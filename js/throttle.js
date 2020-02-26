class Task {
    constructor() {
        this.able = true;
    }

    apply(interval) {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                if (this.able) {
                    resolve();
                } else {
                    reject();
                }
            }, interval);
        });
    }
}

/**
 * 节流器。
 * 
 */
class Throttle {
    constructor() {
        this.time = new Date().getTime();
        this.task = new Task();
    }

    apply(interval) {
        let now = new Date().getTime();
        let delta = now - this.time;
        if (delta > interval) {
            this.task = new Task();
            this.time = now;
            return this.task.apply(interval);
        }
        this.task.able = false;
        this.task = new Task();
        return this.task.apply(interval - delta);
    }
}