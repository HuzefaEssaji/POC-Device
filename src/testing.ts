import a from "./sample/bloodgroups.json"
import b from "./sample/tests.json"
import c from "./sample/allergies.json"
import d from "./sample/prescription.json"
import pat from "./sample/patients.json"
import vis from "./sample/visits.json"
import doc from "./sample/doctors.json"
import pl from "./sample/prescription_list.json"
import al from "./sample/allergies_list.json"
import tl from "./sample/tests_list.json"

import { BloodGroup } from "./models/blood_group";
import { Tests, TestsList } from "./models/tests";
import { Allergies, AllergiesList } from "./models/allergies";
import { Prescription, PrescriptionList } from "./models/prescriptions";
import { Patient } from "./models/patient";
import { Visits } from "./models/visits";
import { Doctors } from "./models/doctor"

export default function TestingData() {
  BloodGroup.bulkCreate(a)
  Tests.bulkCreate(b)
  Allergies.bulkCreate(c)
  Prescription.bulkCreate(d)
  Patient.bulkCreate(pat)
  Doctors.bulkCreate(doc)
  Visits.bulkCreate(vis)
  PrescriptionList.bulkCreate(pl)
  AllergiesList.bulkCreate(al)
  TestsList.bulkCreate(tl)
}
