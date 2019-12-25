/**
 * 单数字字符
 * @param {} c
 */
function isDigit(c) {
    return /^\d$/.test(c);
}

/**
 * 标点符号字符
 * @param {*} c
 */
function isPunctuation(c) {
    return /^[\<\>\(\)\~]$/.test(c);
}

/**
 * 可用于标识符字符。
 * @param {*} c
 */
function isAlpha(c) {
    return /^[0-9A-Za-z_]$/.test(c);
}

/**
 * 词素
 */
class Lexeme {
    constructor(token, info) {
        this.token = token;
        this.info = info;
    }
}

/**
 * 词法分析器。
 *
 */
class Lexer {
    /**
     * 初始化
     */
    constructor() {
        this.text = null; // 文本
        this.index = 0; // 当前字符索引
    }

    /**
     * 词法分析
     */
    lex(text) {
        let able = true;
        let result = [];
        this.text = text;
        this.index = 0;
        setTimeout(() => {
            able = false;
        }, 3000);
        while (able && this.index < this.text.length) {
            let lexeme = this.pop();
            result.push(lexeme);
        }
        if (!able) throw new Error('词法分析超时');
        return result;
    }

    /**
     * 弹出数字
     */
    pop() {
        // 去掉空格
        while (this.text[this.index] == ' ') {
            this.index += 1;
        }
        let c = this.text[this.index];
        if (isDigit(c) || c == '-') {
            return this.popNumber();
        } else if (c == '$') {
            return this.popName();
        } else if (isPunctuation(c)) {
            return this.popOperation();
        }
        return this.popWord();
    }

    /**
     * 弹出数字
     */
    popNumber() {
        let i = this.index;
        let result = [];
        let hasDot = 0;
        if (this.text[i] == '-') {
            result.push('-');
            i++;
        }
        while (i < this.text.length) {
            let c = this.text[i];
            if (isDigit(c)) {
                result.push(c);
                ++i;
            } else if (c == '.' && hasDot < 1) {
                hasDot += 1;
                result.push(c);
                ++i;
            } else if (c == ' ' || isPunctuation(c)) {
                break;
            } else if (c == '-' && result.length == 4) {
                return this.popDate();
            } else {
                return this.popWord();
            }
        }
        this.index = i + 1;

        return new Lexeme('NUMBER', Number(result.join('')));
    }

    /**
     * 弹出日期
     */
    popDate() {
        let i = this.index;
        // 年
        let year = this.text.substr(i, 4);
        if (!/^\d{4}$/.test(year)) {
            throw new Error("词法错误，不是有效的日期年份");
        }
        if (this.text[i + 4] != '-') {
            return this.popWord();
        }

        let d2 = i + 6;
        if (this.text[d2 + 1] == '-') {
            d2 += 1;
        }

        // 月
        let month = this.text.substring(i + 5, d2);
        if (!/^\d{1,2}$/.test(month)) {
            return this.popWord();
        }

        let d3 = d2 + 2;
        if (isDigit(this.text[d3])) {
            d3 += 1;
        }

        // 日
        let day = this.text.substring(d2 + 1, d3);
        if (!/^\d{1,2}$/.test(day)) {
            return this.popWord();
        }
        this.index = d3;
        let info = this.text.substring(i, d3);
        return new Lexeme('DATE', info);
    }

    /**
     * 查询字
     */
    popWord() {
        let start = this.index;
        let i = this.index;
        let limit = 10000;
        while (i <= this.text.length &&
            this.text[i] != ' ' &&
            this.text[i] != '(' &&
            this.text[i] != ')') {
            i++;
            if (limit-- < 0) {
                throw new Error('查询字没有被正确结束或过长。');
            }
        }
        this.index = i;
        let info = this.text.substring(start, i);

        // 是否为保留字
        let lower = info.toLowerCase();
        if (lower == 'and') {
            return new Lexeme('AND');
        }
        if (lower == 'or') {
            return new Lexeme('OR');
        }
        if (lower == 'not') {
            return new Lexeme('NOT');
        }
        return new Lexeme('WORD', info);
    }

    /**
     * 弹出运算符
     */
    popOperation() {
        let i = this.index;
        let c = this.text[i];
        if (c == ')' || c == '(' || c == '>' || c == '~') {
            this.index = i + 1;
            return new Lexeme(c);
        } else if (c == '<') {
            if (this.text[i + 1] == '>') {
                this.index = i + 2;
                return new Lexeme('<>');
            } else {
                this.index = i + 1;
                return new Lexeme(c);
            }
        }
        throw new Error("词法错误，不是有效的操作符");
    }

    /**
     * 处理变量名
     *
     */
    popName() {
        let result = [];
        let c = this.text[this.index];
        if (c != '$') {
            throw new Error("不是有效的变量名。");
        }
        this.index++;
        result.push(c);
        for (;;) {
            c = this.text[this.index++];
            if (isAlpha(c)) {
                result.push(c);
            } else {
                break;
            }
        }
        return new Lexeme('NAME', result.join(''));
    }
}

/**
 * 表达式
 *
 */
class Expression {
    /**
     * 初始化
     */
    constructor() {
        this.index = 0;
        this.lexemes = null;
    }

    /**
     * 字符串化
     * @param {*} node
     * @param {*} scope
     */
    stringify(node, scope) {
        if (node.operation == 'AND' || node.operation == 'OR') {
            return this.stringifyAndOr(node, scope);
        }
        let result = `${node.operation} ${node.operand}`;
        if (node.name) {
            return `${node.name} ${result}`;
        }
        return result;
    }

    /**
     * 字符串化 OR AND
     * @param {*} node
     * @param {*} scope
     */
    stringifyAndOr(node, scope) {
        let left = this.stringify(node.left, true);
        let right = this.stringify(node.right, true);
        let result = `${left} ${node.operation} ${right}`;
        return scope ? `(${result})` : result;
    }

    /**
     * 解析。
     */
    parse(text) {
        let lexer = new Lexer();
        this.index = 0;
        this.lexemes = lexer.lex(text);
        console.log(this.lexemes);
        return this.asExpression();
    }

    /**
     * 解析表达式
     */
    asExpression(isNot) {
        let result = this.asCondition();
        for (;;) {
            let lexeme = this.getAndOr();
            if (lexeme) {
                let left = result;
                result = {
                    isNot: isNot || false,
                    left: left,
                    operation: lexeme.token,
                    right: this.asCondition()
                };
            } else {
                break;
            }
        }
        return result;
    }

    /**
     * 获取 And Or
     */
    getAndOr() {
        let lexeme = this.lexemes[this.index];
        if (lexeme && (lexeme.token == 'AND' || lexeme.token == 'OR')) {
            this.index++;
            return lexeme;
        }
        return null;
    }

    /**
     * 条件。
     */
    asCondition() {
        let lexeme = this.lexemes[this.index];

        let isNot = false;
        let name = null;

        // range（隐含等于）
        if (lexeme.token == 'NUMBER' || lexeme.token == 'DATE') {
            return {
                operation: '=',
                operand: this.asRange()
            };
        }

        // 非（NOT）
        if (lexeme.token == 'NOT') {
            this.index++;
            isNot = true;
            lexeme = this.lexemes[this.index];
        }

        // 变量名
        if (lexeme.token == 'NAME') {
            this.index++;
            name = lexeme.info;
            lexeme = this.lexemes[this.index];
        }

        // 比较运算
        if (lexeme.token == '>' || lexeme.token == '<' || lexeme.token == '<>') {
            this.index += 1;
            let result = {
                isNot: isNot,
                operation: lexeme.token,
                operand: this.asRange()
            };
            if (name) result.name = name;
            return result;
        }

        // 模糊匹配
        if (lexeme.token == '~') {
            this.index++;
            lexeme = this.lexemes[this.index];
            if (lexeme.token != 'WORD' && lexeme.token != 'NUMBER') {
                throw new Error("模糊匹配错误");
            }
            this.index++;
            let result = {
                isNot: isNot,
                operation: '~',
                operand: lexeme.info,
            };
            if (name) result.name = name;
            return result;
        }

        // 括号
        if (lexeme.token == '(') {
            this.index += 1;
            let result = this.asExpression(isNot);
            let lexeme = this.lexemes[this.index];
            if (lexeme.token != ')') {
                throw new Error(`没有正确关闭括号：${this.index} => ${this.lexemes[this.index]}`);
            }
            this.index += 1;
            return result;
        }

        // 隐式模糊匹配
        if (lexeme.token == 'WORD') {
            this.index += 1;
            return {
                isNot: isNot,
                operation: '~',
                operand: lexeme.info
            };
        }
        throw new Error(`无效的条件：${this.index} => ${this.lexemes[this.index]}`);
    }

    /**
     * 带范围的数值。
     */
    asRange() {
        let i = this.index;
        let lexeme = this.lexemes[i];
        if (lexeme.token == 'NUMBER' || lexeme.token == 'DATE') {
            this.index += 1;
            return lexeme.info;
        }
        throw new Error('非法的范围类型');
    }
}

const express = new Expression();
const result = express.parse("$a > 5");
console.log(result);