"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const cors_1 = __importDefault(require("cors"));
const images_controller_1 = require("./images.controller");
const log4js_1 = __importDefault(require("log4js"));
const cors_aloud_json_1 = __importDefault(require("./../../../cors-aloud.json"));
const imagesRouter = express_1.default.Router();
const corsOptions = {
    origin: function (origin, callback) {
        if (cors_aloud_json_1.default.indexOf(origin) !== -1) {
            callback(null, true);
        }
        else {
            callback(new Error("Not allowed by CORS"));
        }
    },
    methods: ["POST"],
    credentials: true,
};
imagesRouter.use((0, cors_1.default)(corsOptions));
try {
    imagesRouter.post("/", images_controller_1.upload, images_controller_1.httpPostImage);
}
catch (e) {
    var logger = log4js_1.default.getLogger("log");
    logger.error(e);
}
exports.default = imagesRouter;
