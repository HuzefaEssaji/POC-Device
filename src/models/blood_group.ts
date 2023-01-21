import { DataTypes } from "sequelize"
import db from "../sequelize";

export const BloodGroup = db.define("blood_group", {
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