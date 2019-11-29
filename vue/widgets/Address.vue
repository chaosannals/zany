<template>
    <div class="address-select">
        <div class="top"></div>
        <div class="viewport">
            <div class="wheel" ref="provinceWheel">
                <div class="content">
                    <div v-for="item in provinces" :key="item.id" class="item">
                        <span>{{item.name}}</span>
                    </div>
                </div>
            </div>
            <div class="wheel" ref="cityWheel">
                <div class="content">
                    <div v-for="item in cities" :key="item.id" class="item">
                        <span>{{item.name}}</span>
                    </div>
                </div>
            </div>
            <div class="wheel" ref="districtWheel">
                <div class="content">
                    <div v-for="item in districts" :key="item.id" class="item">
                        <span>{{item.name}}</span>
                    </div>
                </div>
            </div>
        </div>
        <div class="bottom"></div>
    </div>
</template>

<script>
import store from '@/stores';
import BScroll from 'better-scroll';

export default {
    data() {
        return {
            provinces: [],
            cities: [],
            districts: [],
            province: 0,
            city: 0,
            district: 0,
            provinceWheel: null,
            cityWheel: null,
            districtWheel: null,
        };
    },
    props: {
        detail: {
            default: null,
        },
    },
    watch: {
        province: {
            handler(i) {
                this.city = 0;
                this.district = 0;
                this.cityWheel.wheelTo(0);
                this.districtWheel.wheelTo(0);
                if (this.provinces[i]) {
                    this.cities = this.provinces[i].children;
                    this.districts = this.cities[0].children;
                }
                this.onSelect();
            },
        },
        city: {
            handler(i) {
                this.district = 0;
                this.districtWheel.wheelTo(0);
                if (this.cities[i]) {
                    this.districts = this.cities[i].children;
                }
                this.onSelect();
            },
        },
        district: {
            handler() {
                this.onSelect();
            },
        },
    },
    methods: {
        newScroll(element) {
            return new BScroll(element, {
                wheel: {
                    selectedIndex: 0,
                    rotate: 10,
                    adjustTime: 400,
                    wheelWrapperClass: 'content',
                    wheelItemClass: 'item',
                },
                probeType: 3,
            });
        },
        onSelect() {
            let p = this.provinces[this.province];
            let c = this.cities[this.city];
            let d = this.districts[this.district];
            this.$emit('update:data', {
                province: p,
                city: c,
                district: d,
                text: `${p.name} ${c.name} ${d.name}`,
                value: [ p.id, c.id, d.id ],
            });
            this.$emit('update:detail', {
                province: {
                    id: p.id,
                    level: p.level,
                    parent_id: p.parent_id,
                    order_number: p.order_number,
                    name: p.name,
                    name_en: p.name_en,
                    shortname: p.shortname,
                },
                city: {
                    id: c.id,
                    level: c.level,
                    parent_id: c.parent_id,
                    order_number: c.order_number,
                    name: c.name,
                    name_en: c.name_en,
                    shortname: c.shortname,
                },
                district: {
                    id: d.id,
                    level: d.level,
                    parent_id: d.parent_id,
                    order_number: d.order_number,
                    name: d.name,
                    name_en: d.name_en,
                    shortname: d.shortname,
                },
            });
        },
    },
    created() {
        this.provinces = store.state.area.all;
        if (this.provinces) {
            this.cities = this.provinces[0].children;
            this.districts = this.cities[0].children;
        }
    },
    mounted() {
        // 省份滚轮。
        this.provinceWheel = this.newScroll(this.$refs.provinceWheel);
        this.provinceWheel.on('scrollEnd', () => {
            this.province = this.provinceWheel.getSelectedIndex();
        });

        // 城市滚轮。
        this.cityWheel = this.newScroll(this.$refs.cityWheel);
        this.cityWheel.on('scrollEnd', () => {
            this.city = this.cityWheel.getSelectedIndex();
        });

        // 地区滚轮。
        this.districtWheel = this.newScroll(this.$refs.districtWheel);
        this.districtWheel.on('scrollEnd', () => {
            this.district = this.districtWheel.getSelectedIndex();
        });

        this.provinceWheel.wheelTo(this.province);
        this.cityWheel.wheelTo(this.city);
        this.districtWheel.wheelTo(this.district);
        this.onSelect();
    }
}
</script>

<style lang="scss" scoped>
.address-select {
    position: relative;
    width: 100%;
    height: 100%;

    .viewport {
        display: flex;
        align-items: stretch;
        justify-content: stretch;
        overflow: hidden;
        width: 100%;
        height: 100%;

        .wheel {
            margin-top: 35vw;
            width: 33.3%;

            .content {
                text-align: center;
            }
            
            .item {
                font-size: 5.33vw;
                white-space: nowrap;
            }
        }
    }

    .top {
        position: absolute;
        top: 0;
        left: 0;
        right: 0;
        height: 35vw;
        z-index: 1;
        background: rgba(222, 222, 222, 0.5);
        border-bottom: 1px solid #ddd;
        pointer-events: none;
    }
    .bottom {
        position: absolute;
        left: 0;
        right: 0;
        bottom: 0;
        height: 33vw;
        z-index: 1;
        background: rgba(222, 222, 222, 0.5);
        border-top: 1px solid #ddd;
        pointer-events: none;
    }
}
</style>
