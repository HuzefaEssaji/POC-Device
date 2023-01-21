import { Model, DataTypes } from "sequelize"
import db from "../sequelize";
import { Visits } from "./visits";

export const Prescription = db.define("prescription", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  drug: DataTypes.TEXT,
  dosage: DataTypes.TEXT,
  interval: DataTypes.TEXT,
}, {});

export const PrescriptionList = db.define("prescription_list", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  prescription: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Prescription,
      key: "id"
    }
  },
  visit_id: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Visits,
      key: "id"
    }
  }
}, {});
