"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
require("dotenv").config();
const sequelize_1 = require("sequelize");
let db = new sequelize_1.Sequelize(process.env.DATABASE_URL || "");
exports.default = db;
