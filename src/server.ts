require("dotenv").config();
import http from "http"
import db from "./models/sequelize"
import app from "./app"


const PORT = process.env.PORT || 3000;
const server = http.createServer(app);

async function startServer() {
  server.listen(PORT, () => {
    console.log(`Listening on port ${PORT}...`);
  });
}

db.sync().then(() => {
  startServer();
});