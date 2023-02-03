"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AllergiesList = exports.Allergies = void 0;
const sequelize_1 = require("sequelize");
const sequelize_2 = __importDefault(require("../sequelize"));
const patient_1 = require("./patient");
exports.Allergies = sequelize_2.default.define("allergy", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    name: {
        type: sequelize_1.DataTypes.STRING(45),
        allowNull: false
    },
});
exports.AllergiesList = sequelize_2.default.define("allergy_list", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    patient_id: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: patient_1.Patient,
            key: 'id'
        }
    },
    allergy: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: exports.Allergies,
            key: 'id'
        }
    },
}, {});
