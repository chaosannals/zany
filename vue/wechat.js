import ajax from '@/plugins/ajax';
import router from '@/routes';
// import store from '@/stores';

export default {
    inWechat() {
        let agent = window.navigator.userAgent.toLowerCase();
        return -1 !== agent.indexOf('micromessenger');
    },
    getSignture(type, url) {
        return ajax.post('/user/wechat/jssdk', {
            url: url || this.getLocationHostPath(),
            type: type || 'scanQRCode',
        });
    },
    configure(info) {
        return new Promise((resolve) => {
            window.wx.config({
                debug: false, // 开启调试模式,调用的所有api的返回值会在客户端alert出来，若要查看传入的参数，可以在pc端打开，参数信息会通过log打出，仅在pc端时才会打印。
                appId: info.appId, // 必填，公众号的唯一标识
                timestamp: info.timestamp, // 必填，生成签名的时间戳
                nonceStr: info.nonceStr, // 必填，生成签名的随机串
                signature: info.signature, // 必填，签名
                jsApiList: info.jsApiList, // 必填，需要使用的JS接口列表
            });
            window.wx.ready(() => {
                resolve();
            });
        });
    },
    getLocationHostPath() {
        let result = window.location.href;
        let origin = window.location.origin;
        let path = window.location.pathname;
        if (origin && path) {
            result = `${origin}${path}`;
        }
        return result.replace();
    },
    scanSampleQRCode() {
        window.wx.scanQRCode({
            needResult: 1, // 默认为0，扫描结果由微信处理，1则直接返回扫描结果，
            scanType: ['qrCode', 'barCode'], // 可以指定扫二维码还是一维码，默认二者都有
            success: (response) => {
                var result = response.resultStr;
                if (-1 !== result.indexOf(',')) {
                    result = result.split(',')[1];
                }
                router.push({
                    name: 'sample',
                    query: {
                        number: result,
                    },
                });
            },
        });
    },
};