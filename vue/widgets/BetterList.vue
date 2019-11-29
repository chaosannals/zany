<template>
  <div class="better-list">
    <div class="content">
      <slot></slot>
      <div class="tip">{{finished ? finishedTip : loading ? loadingTip : empty ? emptyTip : tip}}</div>
    </div>
    <div v-if="loading" class="loading-pane">
      <van-loading type="spinner" color="white"/>
    </div>
  </div>
</template>

<script>
import BScroll from "better-scroll";

export default {
  data() {
    return {
      scroller: null
    };
  },
  props: {
    finished: {
      default: false
    },
    loading: {
      default: false
    },
    empty: {
      default: false
    },
    tip: {
      default: "下拉加载更多"
    },
    emptyTip: {
      default: ""
    },
    finishedTip: {
      default: "没有更多"
    },
    loadingTip: {
      default: "加载中"
    }
  },
  watch: {
    loading(v) {
      if (!v) {
        this.scroller.enable();
        this.scroller.refresh();
      } else {
        this.scroller.disable();
      }
    }
  },
  created() {
    this.$nextTick(() => {
      this.scroller = new BScroll(this.$el, {
        scrollX: false,
        scrollY: true,
        click: true,
        pullUpLoad: {
          threshold: -30
        }
      });
      this.scroller.on("pullingUp", () => {
        if (!this.finished && !this.loading) {
          this.$emit("load");
        }
        this.scroller.finishPullUp();
      });
    });
  },
  beforeDestroy() {
    this.scroller.destroy();
  }
};
</script>

<style lang="scss" scoped>
.better-list {
  overflow: hidden;

  .content {
    overflow: hidden;
    width: 100%;

    .tip {
      font-size: 2.6vw;
      text-align: center;
      width: 100%;
      margin: 2vw 0;
    }
  }

  .loading-pane {
    display: flex;
    align-items: center;
    justify-content: center;
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    z-index: 10;
    background: rgba(0, 0, 0, 0.25);
  }
}
</style>
