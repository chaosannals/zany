function makeId(length) {
    let result = [];
    for (let i = 0; i < length; ++i) {
        let v = Math.floor(Math.random() * 16);
        result.push(v.toString(16));
    }
    return result.join();
}