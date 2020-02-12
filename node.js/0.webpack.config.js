const fs = require('fs');
const path = require('path');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');

class Setting {
    constructor() {
        this.entry = {};
        this.output = {
            filename: '[name]/script.js',
            path: path.resolve(__dirname, 'public'),
        };
        this.devtool = "source-map";
        this.performance = { hints: false };
        this.watchOptions = {
            ignored: /node_modules/,
            aggregateTimeout: 300,
            poll: 1000
        };
        this.module = {
            rules: [{
                test: /\.svg$/,
                loader: 'raw-loader',
            }, {
                test: /\.scss$/,
                use: [
                    MiniCssExtractPlugin.loader,
                    'css-loader',
                    {
                        loader: 'sass-loader',
                        options: {
                            implementation: require('sass'),
                        },
                    },
                ],
            }, {
                test: /\.js$/,
                use: [{
                    loader: 'babel-loader',
                }]
            }]
        };
        this.plugins = [
            new MiniCssExtractPlugin({
                filename: '[name]/style.css'
            }),
        ];
    }

    /**
     * 
     * @param {*} folder 
     * @param {*} name 
     */
    addView(folder, name) {
        let setting = {
            inject: false,
            template: path.resolve(__dirname, folder, name, 'main.html'),
            filename: path.resolve(__dirname, 'view', `${name}.html`),
            minify: true
        };
        let scriptPath = path.resolve(__dirname, folder, name, 'script.js');
        if (fs.existsSync(scriptPath)) {
            let stylePath = path.resolve(__dirname, folder, name, 'style.scss');
            this.entry[name] = scriptPath;
            setting.script = `/${name}/script.js`;
            if (fs.existsSync(stylePath)) {
                setting.style = `/${name}/style.css`;
            }
        }
        this.plugins.push(new HtmlWebpackPlugin(setting));
    }

    /**
     * 
     */
    addPage(pagesPath, name) {
        let folderPath = path.resolve(pagesPath, name);
        let mainPath = path.resolve(folderPath, 'main.html');
        if (fs.existsSync(mainPath)) {
            this.addView('pages', name);
        }
        for (let child of fs.readdirSync(folderPath)) {
            let childPath = path.resolve(folderPath, child);
            let stat = fs.statSync(childPath);
            if (stat.isDirectory()) {
                this.addPage(pagesPath, `${name}/${child}`);
            }
        }
    }

    /**
     * 
     */
    addPages() {
        let pagesPath = path.resolve(__dirname, 'pages');
        for (let name of fs.readdirSync(pagesPath)) {
            let filePath = path.resolve(pagesPath, name);
            let stat = fs.statSync(filePath);
            if (stat.isDirectory()) {
                this.addPage(pagesPath, name);
            }
        }
    }

    /**
     * 
     */
    addPanels() {
        let panelsPath = path.resolve(__dirname, 'panels');
        for (let name of fs.readdirSync(panelsPath)) {
            let filePath = path.resolve(panelsPath, name);
            let stat = fs.statSync(filePath);
            if (stat.isDirectory()) {
                this.addView('panels', name);
            }
        }
    }
}

const setting = new Setting();
setting.addPanels();
setting.addPages();
module.exports = setting;