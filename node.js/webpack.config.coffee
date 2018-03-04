path = require 'path'

ExtractTextPlugin = require 'extract-text-webpack-plugin'

extractSCSS = new ExtractTextPlugin 'css/[name].min.css'

module.exports =
    entry:
        styles: path.resolve __dirname, 'main.coffee'
    output:
        filename: 'js/[name].min.js'
        path: path.resolve __dirname, 'public'
    module:
        rules: [
            {
                test: /\.scss$/
                use: extractSCSS.extract {
                    fallback: 'style-loader'
                    use: [
                        'css-loader'
                        'sass-loader'
                    ]
                }
            }
            {
                test: /\.coffee$/
                use: 'coffee-loader'
            }
        ]
    plugins: [
        extractSCSS
    ]