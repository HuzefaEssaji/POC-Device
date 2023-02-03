"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Patient = void 0;
const sequelize_1 = require("sequelize");
const sequelize_2 = __importDefault(require("../sequelize"));
const blood_group_1 = require("./blood_group");
exports.Patient = sequelize_2.default.define("patient", {
    id: {
        type: sequelize_1.DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true
    },
    uid: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        unique: true
    },
    name: {
        type: sequelize_1.DataTypes.STRING(45),
        allowNull: false
    },
    aadhar: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false
    },
    email: {
        type: sequelize_1.DataTypes.STRING,
        allowNull: false,
        validate: {
            isEmail: true,
        }
    },
    father_name: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    mother_name: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    address: {
        type: sequelize_1.DataTypes.TEXT,
        allowNull: false
    },
    date_of_birth: {
        type: sequelize_1.DataTypes.DATEONLY,
        allowNull: false
    },
    blood_group: {
        type: sequelize_1.DataTypes.INTEGER,
        allowNull: false,
        references: {
            model: blood_group_1.BloodGroup,
            key: "id",
        }
    },
    // allergies: {
    //   type: DataTypes.INTEGER,
    //   references: {
    //     model: AllergiesList,
    //     key: "id",
    //   }
    // },
    current_weight: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    current_height: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    gender: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    city: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    pin: {
        type: sequelize_1.DataTypes.INTEGER,
    },
    state: {
        type: sequelize_1.DataTypes.STRING(45),
    },
    // visits: {
    //   type: DataTypes.INTEGER,
    //   references: {
    //     model: PatientVisits,
    //     key: "id"
    //   }
    // }
}, {});
