/**
 * 防抖器
 * 
 * 只执行第一次。
 */
class Debounce {
    constructor() {
        this.busy = true;
    }

    /**
     * 马上执行，间隔内不能重复执行。
     * @param {*} interval 
     */
    apply(interval) {
        return new Promise((resolve, reject) => {
            if (this.busy) {
                reject();
            } else {
                this.busy = true;
                setTimeout(() => {
                    this.busy = false;
                }, interval);
                resolve();
            }
        });
    }

    /**
     * 延迟到间隔时执行第一个，期间所有调用都失败。
     * @param {*} interval 
     */
    delay(interval) {
        return new Promise((resolve, reject) => {
            if (this.busy) {
                reject();
            } else {
                this.busy = true;
                setTimeout(() => {
                    resolve();
                    this.busy = false;
                }, interval);
            }
        });
    }
}