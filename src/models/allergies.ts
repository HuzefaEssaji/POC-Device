import { DataTypes } from "sequelize"
import db from "../sequelize";
import { Patient } from "./patient";

export const Allergies = db.define("allergy", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  name: {
    type: DataTypes.STRING(45),
    allowNull: false
  },
})

export const AllergiesList = db.define("allergy_list", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  patient_id: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Patient,
      key: 'id'
    }
  },
  allergy: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Allergies,
      key: 'id'
    }
  },
}, {});