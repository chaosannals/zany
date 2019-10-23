import axios from 'axios';
import qs from 'qs';

/**
 * ajax 封装
 * 
 */
class Ajax {
    /**
     * 
     */
    constructor() {
        this.axios = axios.create({
            timeout: 30000,
        });
    }

    /**
     * 
     * @param {*} url 
     * @param {*} config 
     */
    get(url, config) {
        return this.axios.get(url, config);
    }

    /**
     * 
     * @param {*} url 
     * @param {*} data 
     * @param {*} config 
     */
    post(url, data, config) {
        return this.axios.post(url, data, config);
    }

    /**
     * 
     * @param {*} url 
     * @param {*} data 
     * @param {*} config 
     */
    upload(url, data, config) {
        let sheet = new FormData();
        for (let key in data) {
            sheet.append(key, data[key]);
        }
        return this.axios.post(url, sheet, config);
    }

    /**
     * 
     * @param {} config 
     */
    request(config) {
        return this.request(config);
    }

    /**
     * 
     * @param {*} url 
     * @param {*} param 
     */
    jsonp(url, param) {
        return new Promise((resolve, reject) => {
            let element = document.createElement('script');
            element.src = url + '?' + qs.stringify(param);
            element.charset = 'utf-8';
            element.onload = () => {
                resolve();
                element.remove();
            };
            element.onerror = e => {
                reject(e);
            }
            document.body.appendChild(element);
        });
    }
}

export const ajax = new Ajax();
export default {
    install(Vue) {
        Vue.prototype.$ajax = ajax;
    }
};