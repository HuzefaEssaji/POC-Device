import { DataTypes } from "sequelize"
import db from "../sequelize";
import { BloodGroup } from "./blood_group";

export const Patient = db.define("patient", {
  id: {
    type: DataTypes.INTEGER,
    autoIncrement: true,
    primaryKey: true
  },
  uid: {
    type: DataTypes.INTEGER,
    allowNull: false,
    unique: true
  },
  name: {
    type: DataTypes.STRING(45),
    allowNull: false
  },
  aadhar: {
    type: DataTypes.INTEGER,
    allowNull: false
  },
  email: {
    type: DataTypes.STRING,
    allowNull: false,
    validate: {
      isEmail: true,
    }
  },
  father_name: {
    type: DataTypes.STRING(45),
  },
  mother_name: {
    type: DataTypes.STRING(45),
  },
  address: {
    type: DataTypes.TEXT,
    allowNull: false
  },
  date_of_birth: {
    type: DataTypes.DATEONLY,
    allowNull: false
  },
  blood_group: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: BloodGroup,
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
    type: DataTypes.STRING(45),
  },
  current_height: {
    type: DataTypes.STRING(45),
  },
  gender: {
    type: DataTypes.STRING(45),
  },
  city: {
    type: DataTypes.STRING(45),
  },
  pin: {
    type: DataTypes.INTEGER,
  },
  state: {
    type: DataTypes.STRING(45),
  },
  // visits: {
  //   type: DataTypes.INTEGER,
  //   references: {
  //     model: PatientVisits,
  //     key: "id"
  //   }
  // }
}, {});