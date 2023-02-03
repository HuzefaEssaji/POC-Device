"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.TestsList = exports.Tests = void 0;
const sequelize_1 = require("sequelize");
const sequelize_2 = __importDefault(require("../sequelize"));
const visits_1 = require("./visits");
exports.Tests = sequelize_2.default.define("test", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    name: {
        type: sequelize_1.DataTypes.STRING(45),
        allowNull: false
    },
}, {});
exports.TestsList = sequelize_2.default.define("test_list", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    visit_id: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: visits_1.Visits,
            key: "id"
        }
    },
    test: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: exports.Tests,
            key: "id"
        }
    },
    comments: {
        type: sequelize_1.DataTypes.TEXT,
    },
    date: {
        type: sequelize_1.DataTypes.DATE,
        allowNull: false,
        defaultValue: new Date()
    }
}, {});
