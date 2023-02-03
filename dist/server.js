"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const http_1 = __importDefault(require("http"));
const app_1 = __importDefault(require("./src/app"));
const sequelize_1 = __importDefault(require("./src/sequelize"));
// import TestingData from "./src/testing";
const PORT = process.env.PORT || 3000;
const server = http_1.default.createServer(app_1.default);
function startServer() {
    return __awaiter(this, void 0, void 0, function* () {
        server.listen(PORT, () => {
            console.log(`Listening on port ${PORT}...`);
        });
    });
}
// db.sync({
//   force: true,
// }).then(() => {
//   TestingData()
//   startServer();
// })
sequelize_1.default.query('SET FOREIGN_KEY_CHECKS = 0', { raw: true }).then(function () {
    sequelize_1.default.sync().then(function () {
        // TestingData()
        startServer();
    });
});
