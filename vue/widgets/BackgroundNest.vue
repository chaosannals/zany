<template>
    <div class="background-nest"></div>
</template>

<script>
import CanvasNest from "canvas-nest.js";

export default {
    data() {
        return {
            nests: []
        };
    },
    methods: {
        randomColor() {
            let red = Math.round(Math.random() * 255);
            let blue = Math.round(Math.random() * 255);
            let green = Math.round(Math.random() * 255);
            return `${red},${blue},${green}`;
        },
        createNests() {
            for (let i = 0; i < 8; ++i) {
                let nest = new CanvasNest(this.$el, {
                    color: this.randomColor(),
                    count: Math.round(Math.random() * 10) + 10
                });
                this.nests.push(nest);
            }
        },
        removeNests() {
            for (let nest of this.nests) {
                nest.destory();
            }
        }
    },
    created() {
        this.$nextTick(() => {
            this.createNests();
        });
    },
    beforeDestory() {
        this.removeNests();
    }
};
</script>

<style lang="scss" scoped>
.background-nest {
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    z-index: -1;
}
</style>