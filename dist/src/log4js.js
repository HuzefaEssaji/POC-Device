"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const log4js_1 = __importDefault(require("log4js"));
log4js_1.default.configure({
    appenders: { log: { type: "file", filename: "console.log" } },
    categories: { default: { appenders: ["log"], level: "error" } },
});
exports.default = log4js_1.default;
