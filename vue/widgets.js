import upperFirst from 'lodash/upperFirst';
import camelCase from 'lodash/camelCase';

export default {
    install(Vue) {
        const requireComponent = require.context(
            '@/views/widgets', // 目录
            false, // 是否遍历子目录
            /\w+\.vue$/, // 匹配模式
        );
        requireComponent.keys().forEach(fileName => {
            const componentConfig = requireComponent(fileName);
            const componentName = upperFirst(
                camelCase(
                    fileName.split('/')
                    .pop().replace(/\.\w+$/, '')
                )
            );
            Vue.component(
                componentName,
                componentConfig.default || componentConfig
            );
        });
    }
}