import { DataTypes } from "sequelize"
import db from "../sequelize";
import { Doctors } from "./doctor";
import { Patient } from "./patient";

export const Visits = db.define("visits", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  patient: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: Patient,
      key: "id",
    }
  },
  date: {
    type: DataTypes.DATE,
    allowNull: false,
    defaultValue: new Date()
  },
  weight: {
    type: DataTypes.STRING(45),
  },
  height: {
    type: DataTypes.STRING(45),
  },
  temperature: {
    type: DataTypes.STRING(45),
  },
  bp: {
    type: DataTypes.STRING(45),
  },
  ecg: {
    type: DataTypes.TEXT,
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
    type: DataTypes.INTEGER,
    references: {
      model: Doctors,
      key: "id"
    }
  }
}, {});
