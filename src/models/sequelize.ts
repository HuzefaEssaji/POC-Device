import { Sequelize } from "sequelize";
const db = new Sequelize(process.env.DATABASE_URL || "");

db.authenticate()
  .then(() => {
    console.log("Connection has been established successfully.");
  })
  .catch((err: any) => {
    console.error("Unable to connect to the database:", err);
  });

export default db;
