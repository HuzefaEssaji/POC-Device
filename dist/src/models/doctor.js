"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Doctors = void 0;
const sequelize_1 = require("sequelize");
const sequelize_2 = __importDefault(require("../sequelize"));
exports.Doctors = sequelize_2.default.define("doctor", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    name: {
        type: sequelize_1.DataTypes.STRING(45),
        allowNull: false
    },
    email: {
        type: sequelize_1.DataTypes.STRING,
        allowNull: false,
        validate: {
            isEmail: true,
        }
    },
    branch: {
        type: sequelize_1.DataTypes.STRING(45),
        allowNull: false
    },
    // visits_done: {
    //   type: DataTypes.INTEGER,
    //   references: {
    //     model: PatientVisits,
    //     key: "id"
    //   }
    // }
}, {});
