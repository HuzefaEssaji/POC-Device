import { DataTypes } from "sequelize"
import db from "../sequelize";
import { Visits } from "./visits";

export const Tests = db.define("test", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  name: {
    type: DataTypes.STRING(45),
    allowNull: false
  },
}, {});

export const TestsList = db.define("test_list", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  visit_id: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Visits,
      key: "id"
    }
  },
  test: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Tests,
      key: "id"
    }
  },
  comments: {
    type: DataTypes.TEXT,
  },
  date: {
    type: DataTypes.DATE,
    allowNull: false,
    defaultValue: new Date()
  }
}, {});