"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Visits = void 0;
const sequelize_1 = require("sequelize");
const sequelize_2 = __importDefault(require("../sequelize"));
const doctor_1 = require("./doctor");
const patient_1 = require("./patient");
exports.Visits = sequelize_2.default.define("visits", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    patient: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: patient_1.Patient,
            key: "id",
        }
    },
    date: {
        type: sequelize_1.DataTypes.DATE,
        allowNull: false,
        defaultValue: new Date()
    },
    weight: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    height: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    temperature: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    bp: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    ecg: {
        type: sequelize_1.DataTypes.TEXT,
    },
    // prescriptions: {
    //   type: DataTypes.INTEGER,
    //   references: {
    //     model: PrescriptionList,
    //     key: "id",
    //   }
    // },
    // tests: {
    //   type: DataTypes.INTEGER,
    //   references: {
    //     model: TestsList,
    //     key: "id",
    //   },
    // },
    doctor_visited: {
        type: sequelize_1.DataTypes.INTEGER,
        references: {
            model: doctor_1.Doctors,
            key: "id"
        }
    }
}, {});
