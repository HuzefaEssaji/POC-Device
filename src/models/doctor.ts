import { DataTypes } from "sequelize"
import db from "../sequelize";

export const Doctors = db.define("doctor", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  name: {
    type: DataTypes.STRING(45),
    allowNull: false
  },
  email: {
    type: DataTypes.STRING,
    allowNull: false,
    validate: {
      isEmail: true,
    }
  },
  branch: {
    type: DataTypes.STRING(45),
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
