import { BloodGroup } from "./models/blood_group";
import { Tests } from "./models/tests";
import { Allergies } from "./models/allergies";
import { Prescription } from "./models/prescriptions";

import a from "./sample/bloodgroups.json"
import b from "./sample/tests.json"
import c from "./sample/allergies.json"
import d from "./sample/prescription.json"
import pat from "./sample/patients.json"
import { Patient } from "./models/patient";

export default function TestingData() {
  BloodGroup.bulkCreate(a)
  Tests.bulkCreate(b)
  Allergies.bulkCreate(c)
  Prescription.bulkCreate(d)
  Patient.bulkCreate(pat)
}
