"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.PrescriptionList = exports.Prescription = void 0;
const sequelize_1 = require("sequelize");
const sequelize_2 = __importDefault(require("../sequelize"));
const visits_1 = require("./visits");
exports.Prescription = sequelize_2.default.define("prescription", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    drug: sequelize_1.DataTypes.TEXT,
    dosage: sequelize_1.DataTypes.TEXT,
    interval: sequelize_1.DataTypes.TEXT,
}, {});
exports.PrescriptionList = sequelize_2.default.define("prescription_list", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    prescription: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: exports.Prescription,
            key: "id"
        }
    },
    visit_id: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: visits_1.Visits,
            key: "id"
        }
    }
}, {});
