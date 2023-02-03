"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const images_router_1 = __importDefault(require("./images/images.router"));
const api = express_1.default.Router();
api.use("/upload", images_router_1.default);
exports.default = api;
