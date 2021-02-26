module.exports = {
    publicPath: 'production' == process.env.NODE_ENV ? '/folder' : '/',
    outputDir: '../website/folder',
    indexPath: '../absolute/outputdir',
    devServer: {
        port: 8080,
        proxy: {
            '/api': {
                target: 'http://127.0.0.1',
                ws: true,
                changeOrigin: true,
            },
        },
    },
};