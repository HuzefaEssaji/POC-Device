require("dotenv").config();
import { Sequelize } from "sequelize";
let db = new Sequelize(process.env.DATABASE_URL || "");
export default db;