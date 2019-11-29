<template>
    <div class="foreign-country-select">
        <div v-for="continent in continents" :key="continent.id" class="continent">
            <h5>{{continent.text}}</h5>
            <div class="group">
                <template v-for="(item, i) in regions">
                    <template v-if="item.parentId == continent.id">
                        <div v-if="-1 != result.indexOf(i)" :key="item.id" @click="onCancel(i)" class="item active">
                            <div>{{item.text}}</div>
                        </div>
                        <div v-else :key="item.id" @click="onSelect(i)" class="item">
                            <div>{{item.text}}</div>
                        </div>
                    </template>
                </template>
            </div>
        </div>
    </div>
</template>

<script>
import store from '@/stores';

export default {
    data() {
        return {
            result: [],
        };
    },
    props: {
        data: {
            default: null,
        },
        type: {
            default: 'ForeignCountry',
        },
        detail: {
            default: null,
        },
    },
    computed: {
        regions() {
            return this.initRegions();
        },
        continents() {
            return this.initContinents();
        },
    },
    methods: {
        initRegions() {
            let result = [];
            let regions = store.state.area.regions;
            for (let region of regions) {
                result.push({
                    id: region.id,
                    value: region.id,
                    text: region.name,
                    parentId: region.parent_id,
                });
            }
            return result;
        },
        initContinents() {
            let result = [];
            let continents = store.state.area.continents;
            for (let continent of continents) {
                result.push({
                    id: continent.id,
                    value: continent.id,
                    text: continent.name,
                });
            }
            return result;
        },
        onSelect(i) {
            this.result.push(i);
            this.onChange();
        },
        onCancel(i) {
            let index = this.result.indexOf(i);
            this.result.splice(index, 1);
            this.onChange();
        },
        onChange() {
            let result = [];
            let content = [];
            let detail = [];
            this.result.sort();
            for (let i of this.result) {
                let item = this.regions[i];
                result.push(item.id);
                content.push(item.text);
                detail.push(item);
            }
            this.$emit('update:data', {
                text: content.join(','),
                value: result,
            });
            this.$emit('update:detail', detail);
        },
    },
    mounted() {
        if (this.data) {
            for (let key in this.items) {
                let i = Number(key);
                let item = this.items[i];
                for (let id of this.data.value) {
                    if (item.id == id && -1 == this.result.indexOf(i)) {
                        this.result.push(i);
                    }
                }
            }
        }
    },
};
</script>

<style lang="scss" scoped>
.foreign-country-select {
    width: 100%;
    height: 100%;
    overflow-y: auto;

    .continent {
        h5 {
            margin: 2vw 3vw;
            font-size: 3.733vw;
            font-weight: bold;
        }
    }

    .group {
        display: flex;
        flex-wrap: wrap;
        
        .item {
            box-sizing: border-box;
            overflow-x: hidden;
            width: 33.3%;
            padding: 1.66vw 3.33vw;
            font-size: 3.733vw;
            text-align: center;

            & > div {
                overflow: hidden;
                white-space: nowrap;
                height: 8.13vw;
                line-height: 8.13vw;
                white-space: nowrap;
                border: 1px solid #F5F5F5;
                border-radius: 4.06vw;
                background: #F5F5F5;
            }
            &.active > div {
                color: #2B5993;
                border: 1px solid #2B5993;
            }
        }
    }
}
</style>
