const path = require('path')

const ExtractTextPlugin = require('extract-text-webpack-plugin')

const extractSCSS = new ExtractTextPlugin('css/[name].min.css')

module.exports = {
    entry: {
        styles: path.resolve(__dirname, 'main.coffee')
    },
    output: {
        filename: 'js/[name].min.js',
        path: path.resolve(__dirname, 'public')
    },
    module: {
        rules: [
            {
                test: /\.scss$/,
                use: extractSCSS.extract({
                    fallback: 'style-loader',
                    use: [
                        'css-loader',
                        'sass-loader'
                    ]
                })
            }, {
                test: /\.js$/,
                use: [
                    {
                        loader: 'babel-loader',
                        options: {
                            presets: [ 'es2015' ],
                            ignore: [ 'jsencrypt' ]
                        }
                    }
                ]
            }
        ]
    },
    plugins: [ extractSCSS ]
};