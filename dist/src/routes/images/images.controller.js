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
exports.httpPostImage = exports.upload = void 0;
const multer_1 = __importDefault(require("multer"));
const path_1 = __importDefault(require("path"));
const log4js_1 = __importDefault(require("../../log4js"));
var logger = log4js_1.default.getLogger("log");
const maxSize10 = 1 * 1024 * 1024 * 10;
exports.upload = (0, multer_1.default)({
    storage: multer_1.default.diskStorage({
        destination: path_1.default.join(__dirname, "../../../uploads"),
        filename: (req, file, cb) => {
            const filename = `${Date.now()}_${file.originalname}`;
            req.filename = filename;
            cb(null, filename);
        },
    }),
    limits: {
        fileSize: 1 * 1024 * +(process.env.FILE_SIZE || 0) ? 1 * 1024 * +(process.env.FILE_SIZE || 0) : maxSize10,
    },
}).single("uploadimg");
function httpPostImage(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        if (req.file) {
            logger.error(JSON.stringify(req.file));
            res.status(201).json({ img: `images/${req.filename}` });
        }
        else {
            res.status(200).json({ message: "Failed to upload" });
        }
    });
}
exports.httpPostImage = httpPostImage;
