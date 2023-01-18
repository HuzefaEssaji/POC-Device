/**
 *  Calculator functions.
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 *  specific language governing permissions and limitations
 *  under the License.
 */ 

/* CONSTANTS */
var errorDelay = 750;   //in msec

/* GLOBALS */
var language = 'en';	// Updates based on the <select> within document ready

$(document).ready(function() {
	if (CONVERT_SLIDERS) {		// this flag is specifically set by IE 9 and lower because we have a plugin for FireFox and don't care about old WebKit
		convertSliders();
	}
	
	// Legacy support of #basic tags
	if (location.href.toLowerCase().indexOf("#basic") >= 0) {
		var basicUri = new URI(window.location.href.split("#")[0]);
		if (!basicUri.hasQuery('basic')) {
			basicUri.addQuery('basic','true');
		}
		window.location.href = basicUri.toString();
	}
	
	// Localization support
	// First, check the URL (if param 'lang' is set)
	var uri = new URI(window.location);
	if (uri.hasQuery('lang')) {
		language = uri.search(true)['lang'];
		$('#selectLocalization').val(language);
		LoadLocalizationData(language);
	} else {
		// Nothing in the param list -- load default English
		language = $('#selectLocalization').val();
		if (language == '') { language = 'en'; }
		LoadLocalizationData(language);
	}
	
	// setup offline mode
	if ('applicationCache' in window) {
		window.applicationCache.addEventListener('checking', offlineStatusChanged, false);
		window.applicationCache.addEventListener('noupdate', offlineStatusChanged, false);
		window.applicationCache.addEventListener('downloading', offlineStatusChanged, false);
		window.applicationCache.addEventListener('cached', offlineStatusChanged, false);
		window.applicationCache.addEventListener('updateready', offlineStatusChanged, false);
		window.applicationCache.addEventListener('obsolete', offlineStatusChanged, false);
		window.applicationCache.addEventListener('error', offlineStatusChanged, false);
	}
	
	// "basic" vs. enhanced functionality
	setFormulaById('framingham2008');
	if (!BasicView()) {
		// Load the normal page (the page should be setup by default to support the 'normal' functionality without any JavaScript magic
		
	} else {
		// Load an "basic" version of the page
		// Reset the toggle button
		$('#toggleBasicView').text(LocalizeText('SwitchEnhanced',language));
		$('#toggleBasicView').click(function() {
		
			var basicUri = new URI(window.location.href);
			basicUri.removeQuery('basic');
			if (language != 'en') {
				basicUri.addQuery('lang',language);
			}
			window.location = basicUri.toString();
		});
		
		// Hide some of the treatments
		$('li[data-benefit="vitaomeg"]').hide();
		$('li[data-benefit="bp"]').hide();
		$('li[data-benefit="fibrates"]').hide();
		$('li[data-benefit="niacin"]').hide();
		$('li[data-benefit="ezetimibe"]').hide();
		$('li[data-benefit="metformin"]').hide();
		$('li[data-benefit="sulfonylureas"]').hide();
		$('li[data-benefit="insulins"]').hide();
		$('li[data-benefit="glitazones"]').hide();
		$('li[data-benefit="glp"]').hide();
		$('li[data-benefit="dpp-4"]').hide();
		$('li[data-benefit="meglit"]').hide();
		$('li[data-benefit="sglt"]').hide();
		
		// "Unfill" the textboxes to force the user to input data
		$('#age').val('').change();
		$('#sbp').val('').change();
		$('#chol_mmol').val('').change();
		$('#chol_mgdl').val('').change();
		$('#hdl_mmol').val('').change();
		$('#hdl_mgdl').val('').change();
		$('#height_cm_label').val('').change();
		$('#height_in_label').val('').change();
		$('#weight_kg_label').val('').change();
		$('#weight_lbs_label').val('').change();
		
		// Hide some of the calculators
		/*
		$('li[data-calc="chd"]').hide();
		$('li[data-calc="mi"]').hide();
		$('li[data-calc="stroke"]').hide();
		*/
		
		// Make Framingham look more normal...
		/*
		$('#liFramingham').attr('id','liFraminghamSimple');		// Changing the ID removes much of the Framingham-specific styling in the CSS
		$('li[data-calc="cvd"]').attr('onclick','');
		$('#liFraminghamSimple').attr('data-calc','framingham2008');
		$('#liFraminghamSimple').click(function() {
			setFormula(this);
			$('#liFraminghamSimple').addClass('active');
		});
		*/
		
		// Hide some of the results table
		$('#trScoreBad').hide();
		$('#trScoreBadAdd').hide();
		// Change the icon in the results table
		$('#trScoreBadSum td img').attr('src','imgs/bad.png');
	}
	
	// detect if we're running standalone
	// if (window.navigator.standalone)
});

function PrintView() {
	if ($('#outcome').hasClass('opacity10')) { return; }	// If opacity is activated, there's something wrong with the user input

	$("#cssPrintable").load(function(){
	window.print();
	}).attr('href', 'static/printable.css');
}

function RemovePrintView() {
	$('#cssPrintable').attr('href','');
}

function SwitchToBasicView() {
	var uri = new URI(window.location.href);
	uri.addQuery('basic','true');
	
	if (language == 'en') {
		if (uri.hasQuery('lang')) {
			uri.removeQuery('lang');
		}
	} else {
		uri.addQuery('lang',language);
	}

	window.location.href = uri.toString();
}

function BasicView() {
	
	var uri = new URI(window.location.href);
	if (uri.hasQuery('basic')) {
		return (uri.search(true)['basic'] == 'true');
	} else {
		return false;
	}
}
 
function gender(item) {
	if (item) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	
	return $('#male').hasClass('active') ? 1 : 0;
}

function race(item) {
	if (item) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	return $('#black').hasClass('active') ? 1 : 0;
}

function ethnicity() {
	return $('#ethnicity').val();
}

function male() {
	return 1 == gender();
}

function female() {
	return 0 == gender();
}

function black() {
	return 1 == race();
}
function nonblack() {
	return 0 == race();
}

function smoker(item) {
	if ('qrisk' == _formula_id) {
		return (parseInt($('#smoke_cat').val()) > 1);
	} else if ('predict' == _formula_id) {
		return (parseInt($('#smoke_cat_trichotomous').val()) > 1);
	} else {
		if (item) {
			$(item).addClass('active').siblings().removeClass('active');
		}	
		return $('#smoker_yes').hasClass('active') ? 1 : 0;
	}
}

function totalchol() {
	if (_useMMOL) {
		return $('#totalchol_mmol').val() *1;
	}
	
	// 1 mmol/L == 38.666666 mg/dL
	return $('#totalchol_mgdl').val() / 38.666666;
}

function hdlchol() {
	if (_useMMOL) {
		return $('#hdlchol_mmol').val() *1;
	}
	
	// 1 mmol/L == 38.666666 mg/dL
	return $('#hdlchol_mgdl').val() / 38.666666;
}

function height() {
	if (_useCm) {
		return $('#height_cm_label').val() *1;
	}
	
	// 2.54 cm = 1 inch
	return $('#height_in_label').val() * 2.54;
}

function weight() {
	if (_useKg) {
		return $('#weight_kg_label').val() *1;
	}
	
	// 1 kg = 2.2 lbs
	return $('#weight_lbs_label').val() / 2.2;
}

function bodymassindex() {
	if ((weight() == 0) || (height() == 0)) { return 0; }
	return weight() / (height()/100 * height()/100);
}

function diabetes(item) {
	if ('qrisk' == _formula_id) {
		return (parseInt($('#dm_cat').val()) > 0);
	} else {
		if (item) {
			$(item).addClass('active').siblings().removeClass('active');
		}
		return $('#diabetes_yes').hasClass('active') ? 1 : 0;
	}
}

function famhistory(item) {
	if (item) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	return $('#famhistory_yes').hasClass('active') ? 1 : 0;
}

function ckd(item) {
	if (item) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	return $('#ckd_yes').hasClass('active') ? 1 : 0;
}

function afib(item) {
	if (item) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	return $('#afib_yes').hasClass('active') ? 1 : 0;
}

function ra(item) {
	if (item) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	return $('#ra_yes').hasClass('active') ? 1 : 0;
}

function systole() {
	return $('#sbp').val() *1;
}

function bptreatment(item) {
	if (item && !$(item).parent().hasClass('disabled')) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	
	return $('#bptreatment_yes').hasClass('active') ? 1 : 0;
}

function lipidtreatment(item) {
	if (item && !$(item).parent().hasClass('disabled')) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	
	return $('#lipidtreatment_yes').hasClass('active') ? 1 : 0;	
}

function apactreatment(item) {
	if (item && !$(item).parent().hasClass('disabled')) {
		$(item).addClass('active').siblings().removeClass('active');
	}
	
	return $('#apactreatment_yes').hasClass('active') ? 1 : 0;	
}

function isNumeric(n) {
  return !isNaN(parseFloat(n)) && isFinite(n);
}

function adjustSliderAllowZeroOrEmpty(txt_id, slider_id, alert_info, sender, no_calc) {

	// Who sent you?
	var val = $('#'+txt_id).val();
	var min = $('#'+slider_id).attr('min');
	var max = $('#'+slider_id).attr('max');
	
	if ($(sender).attr('id') == txt_id) {
		val = $('#'+txt_id).val();
	} else {
		// Trust the slider by default if a sender isn't known or doesn't match
		val = $('#'+slider_id).val();
	}
	
	if ((val.trim().length == 0) || (parseFloat(val) == 0)) {
		val = 0;
		$('#'+txt_id).val(val);
	} else {
		// The value entered is not empty and not zero -- do a normal check
		adjustSlider(txt_id, slider_id, alert_info, sender, no_calc);
	}

	//$('#'+txt_id).removeClass('errorTextbox');		// Leave the textbox as red, but allow the calculation to proceed
	adjust(txt_id, sender, no_calc);
}

function adjustSlider(txt_id, slider_id, alert_info, sender, no_calc) {
	// Who sent you?
	if ($(sender).attr('id') == txt_id) {
		// Textbox input is raw -- needs to be validated
		var txt_val = $('#'+txt_id).val();
		var min = $('#'+slider_id).attr('min');
		var max = $('#'+slider_id).attr('max');
		
		// Check if a number
		if (!isNumeric(txt_val)) {
			$('#outcome').addClass('opacity10');	// This class will be removed in the CALC() function -- do not remove it in the else {} portion because other things may be invalid
			$('#'+txt_id).addClass('errorTextbox');
			return false;
		}
		
		// Gently warn the user about min/max errors.  Changing the textbox input with min/max gets overzealous because the min/max check can occur mid-typing (eg, typing the '3' for '30' will trigger a check and change)
		if (parseFloat(txt_val) < parseFloat(min)) {

			$('#outcome').addClass('opacity10');
		    setTimeout(function () {
		        if (parseFloat($('#' + txt_id).val()) < parseFloat(min)) {
		            $('#' + alert_info['alert_id']).html(alert_info['label'] + ' ' + LocalizeText('MustBeBetween',language) + ' ' + min + ' ' + LocalizeText('and',language) + ' ' + max + ' ' + alert_info['suffix']).show();
		            $('#' + txt_id).addClass('errorTextbox');
		        }
		    }, errorDelay);
			
			return;
		}
		if (parseFloat(txt_val) > parseFloat(max)) {

			$('#outcome').addClass('opacity10');
		    setTimeout(function () {
		        if (parseFloat($('#' + txt_id).val()) > parseFloat(max)) {
		            $('#' + alert_info['alert_id']).html(alert_info['label'] + ' ' + LocalizeText('MustBeBetween',language) + ' ' + min + ' ' + LocalizeText('and',language) + ' ' + max + ' ' + alert_info['suffix']).show();
		            $('#' + txt_id).addClass('errorTextbox');
		        }
		    }, errorDelay);

		    return;
		}
		
		$('#'+slider_id).val(txt_val);
	} else {
		// Trust the slider by default if a sender isn't known or doesn't match
		$('#'+txt_id).val($('#'+slider_id).val());
	}
	
	$('#'+txt_id).removeClass('errorTextbox');
	adjust(txt_id, sender, no_calc);
}

function adjust(elem_id, sender, no_calc) {
	adjustValue(elem_id, $(sender).val(), no_calc);
}

function adjustValue(elem_id, value, no_calc) {
	
	// systole was adjusted, show/hide some hints
	if ('sbp' == elem_id) {
		if (value > 120) {
			$('#bptreatment_toggle').removeClass('disabled');
			$('#bptreatment_hint').hide();
		}
		else if (!$('#bptreatment_toggle').hasClass('disabled')) {
			bptreatment($('#bptreatment_no'));
			$('#bptreatment_toggle').addClass('disabled');
			$('#bptreatment_hint').show();
		}
	}
	
	// apply and calculate -- this is no longer needed due to the switch from text-based labels to input-based textboxes
	//$('#' + elem_id).text(value ? Math.round(value * 10) / 10 : 0);
	
	if (!no_calc) {
		CALC();
	}
}


function toggleBenefit(elem) {
	var obj = $(elem);
	if (!obj) {
		return;
	}
	obj.toggleClass('active').siblings().removeClass('active');		// for now limited to ONE choice
	
	// find correct text or list items
	var text = '';
	if (obj.hasClass('active')) {
		var bene = obj.data('benefit');
		if (bene in _benefit_risks) {
			var res = _benefit_risks[bene];
			if ('string' == typeof(res)) {
				text = res;
			}
			else if (res && res.length > 0) {
				text = "<ul><li>" + res.join("</li><li>") + "</li></ul>";
			}
		}
		else {
			alert("There is no harm information for the intervention" + " \"" + bene + "\"");	// Do not localize
		}
	}
	
	// show/hide information text
	$('#benefit_information').remove();
	$('h3.relativeBenefit > span').removeClass('active');
	if (text && text.length > 0) {
		var html = "<h3 data-lang-id=\"HarmOfIntervention\">" + LocalizeText("HarmOfIntervention",language) + "</h3><p>" + text + '</p>';
		var li = $('<li/>', {'id': 'benefit_information'}).html(html);
		
		// we only want to append to the item BEFORE a line break, not always after the clicked item because that might put some innocent items on the next line
		var offset = obj.offset().top;
		while (obj.next() && obj.next().offset() && offset >= obj.next().offset().top) {
			obj = obj.next();
		}
		obj.after(li);

		$('h3.relativeBenefit > span').addClass('active');
	}
	
	CALC();
}

function returnBenefitName(formula_id) {
	var active = $('#benefit_estimates').find('li').map(function(idx, item) {
		var elem = $(item);
		if (elem.hasClass('active')) {
			return elem.data('benefit');
		}
	}).get();
	
	var max = 0;
	for (var bf in _benefit[formula_id]) {
		if (!active.contains(bf)) {
			continue;
		}
		
		return bf;
	}
}

/**
 *  Calculates the current benefit for the given formula.
 */
function benefit(formula_id) {
	if (!formula_id || ! (formula_id in _benefit)) {
		alert("I cannot currently calculate benefits for this formula: " + (formula_id ? formula_id : "not defined"));	// Intentionally not localized
		return 0;
	}
	
	// get active benefits
	var active = $('#benefit_estimates').find('li').map(function(idx, item) {
		var elem = $(item);
		if (elem.hasClass('active')) {
			return elem.data('benefit');
		}
	}).get();
	
	// get maximum benefit percentage
	var max = 0;
	for (var bf in _benefit[formula_id]) {
		if (!active.contains(bf)) {
			continue;
		}
		
		// for the BP meds ("bp"), it ONLY applies if BP is "_bp_threshold" and higher
		if ('bp' == bf && !AboveThresholdForBpMeds()) {
			continue;
		}
		
		if ('smoking' == bf) {
			continue;
		}
		
		var this_benefit = _benefit[formula_id][bf];
		
		// not a number, assume it's a dictionary in the form {'default': 0, 'diabetes': 10}
		if ('number' != typeof(this_benefit)) {
			var def = 0;
			var use = null;
			for (var t in this_benefit) {
				if ('default' == t) {
					def = this_benefit[t];
				}
				else {
					var func = window[t];
					if (!func || 'function' != typeof(func)) {
						alert("The benefit for " + bf + " of type " + t + " is invalid, needs to be a function name"); // Intentionally not localized
					}
					else if (func()) {
						use = this_benefit[t];
						break;
					}
				}
			}
			
			this_benefit = (null !== use) ? use : def;
		}
		
		// make sure we have a number and add to our array
		if ('number' != typeof(this_benefit)) {
			console.error(this_benefit);
			alert("Not a numerical value for benefit " + bf + ": " + this_benefit); // Intentionally not localized
		}
		else if (this_benefit > max) {
			max = this_benefit;
		}
	}
	
	return max;
}


/**
 *  Sets the active formula from the given element.
 */
function setFormula(item) {
	setFormulaById($(item).data('calc'));
}

/**
 *  Sets the currently active formula to the given id.
 */
function setFormulaById(formula_id) {
	if (!formula_id) {
		return;
	}
	
	_formula_id = formula_id;
	
	$('#formula_selector').find('li').removeClass('active').filter(function(index) {
		return $(this).data('calc') == _formula_id;
	}).addClass('active');
	// showImages(formula_id);
	
	// Hide all fields that are not universally used by all calculators
	$('.CalcSpecificField').hide();
	$('#qrisk_disclaimer').hide();
	
	// Specific fields for Framingham
	if ('framingham2008' == formula_id) {
		$('#smoker_dicotomous').show();
		$('#dm_dichotomous').show();
		$('#divFamilyHistoryOfEarlyCHD').show();
		$('#CkdExplanation').show();
	}
	
	// Specific fields for ASCVD
	if ('ascvd' == formula_id) {
		$('#divRace').show();
		$('#smoker_dicotomous').show();
		$('#dm_dichotomous').show();
		$('#divFamilyHistoryOfEarlyCHD').show();
		$('#CkdExplanation').show();
	}
	
	// Specific fields for QRISK
	if ('qrisk' == formula_id) {
		$('#divEthnicity').show();
		$('#smoker_detailed').show();
		$('#dm_detailed').show();
		$('.qrisk_questions').show();
		$('#qrisk_disclaimer').show();
	}
	
	// Specific fields for PREDICT
	if ('predict' == formula_id) {
		$('#divLipidTreatment').show();
		$('#divApacTreatment').show();
		$('#dm_dichotomous').show();
		$('#smoker_tricotomous').show();
		$('#divAfib').show();
		$('#divDeprivationIndex').show();
		$('#CkdExplanation').show();
		$('#divEthnicity_PREDICT').show();
		$('#divFamilyHistoryYesNo').show();
	}

	// Hide/show for Framingham
	/*
	if (('framingham2008' == formula_id) || ('cvd' == formula_id) || ('chd' == formula_id) || ('mi' == formula_id) || ('stroke' == formula_id)) {
		$('#BpPriorToDrugs').show();
	} else {
		$('#BpPriorToDrugs').hide();
	}
	*/
	 
	// Should the "Risk Time Period" option be enabled?
	if (('framingham2008' == formula_id) || ('qrisk' == formula_id) || ('ascvd' == formula_id)) {
	    $('#rangeTime').prop('disabled', true);
	    $('#time').prop('disabled', true);
	    $('#rangeTime').val(10);
	    $('#time').val(10);
	    $('#divTime').hide();
		$('#time_fixed').show();
		adjust('time', $('#rangeTime'), true);
		$('#time_fixed').text(LocalizeText("10years",language));
		
	} else if ('predict' == formula_id) {
		
	    $('#rangeTime').prop('disabled', true);
	    $('#time').prop('disabled', true);
	    $('#rangeTime').val(5);
	    $('#time').val(5);
	    $('#divTime').hide();
		$('#time_fixed').show();
		adjust('time', $('#rangeTime'), true);
		$('#time_fixed').text(LocalizeText("5years",language));
		
	} else {
	    $('#divTime').show();
	    $('#time').prop('disabled', false);
	    $('#rangeTime').prop('disabled', false);
	    $('#time_fixed').hide();
	}
	
	// Override for Basic version
	if (BasicView()) {
	    $('#divTime').hide();
		$('#time_fixed').show();	
	}
	
	calculate(formula_id);
}


/**
 *  Calculates the currently active formula.
 */
function CALC() {
	calculate(_formula_id);
}

/**
 *  ASCVD coefficients by age/race
 */
 function BlackFemale() {
    this.Age = 17.1141;
    this.AgeSquared = 0;
    this.TC = 0.9396;
    this.AgexTC = 0;
    this.HDL = -18.9196;
    this.AgexHDL = 4.4748;
    this.TreatedBP = 29.2907;
    this.AgexTreatedBP = -6.4321;
    this.UntreatedBP = 27.8197;
    this.AgexUntreatedBP = -6.0873;
    this.Smoker = 0.6908;
    this.AgexSmoker = 0;
    this.Diabetes = 0.8738;
    this.BaselineSurvival = 0.95334;
    this.OverallMean = 86.6081;
}
function BlackMale() {
    this.Age = 2.469;
    this.AgeSquared = 0;
    this.TC = 0.302;
    this.AgexTC = 0;
    this.HDL = -0.307;
    this.AgexHDL = 0;
    this.TreatedBP = 1.916;
    this.AgexTreatedBP = 0;
    this.UntreatedBP = 1.809;
    this.AgexUntreatedBP = 0;
    this.Smoker = 0.549;
    this.AgexSmoker = 0;
    this.Diabetes = 0.645;
    this.BaselineSurvival = 0.89536;
    this.OverallMean = 19.5425;
}
function WhiteFemale() {
    this.Age = -29.799;
    this.AgeSquared = 4.884;
    this.TC = 13.54;
    this.AgexTC = -3.114;
    this.HDL = -13.578;
    this.AgexHDL = 3.149;
    this.TreatedBP = 2.019;
    this.AgexTreatedBP = 0;
    this.UntreatedBP = 1.957;
    this.AgexUntreatedBP = 0;
    this.Smoker = 7.574;
    this.AgexSmoker = -1.665;
    this.Diabetes = 0.661;
    this.BaselineSurvival = 0.96652;
    this.OverallMean = -29.1817;
}
function WhiteMale() {
    this.Age = 12.344;
    this.AgeSquared = 0;
    this.TC = 11.853;
    this.AgexTC = -2.664;
    this.HDL = -7.99;
    this.AgexHDL = 1.769;
    this.TreatedBP = 1.797;
    this.AgexTreatedBP = 0;
    this.UntreatedBP = 1.764;
    this.AgexUntreatedBP = 0;
    this.Smoker = 7.837;
    this.AgexSmoker = -1.795;
    this.Diabetes = 0.658;
    this.BaselineSurvival = 0.91436;
    this.OverallMean = 61.1816;
}


/**
 *  Our main calculation formula.
 */
function calculate(formula_id) {
	// Clear our printables in the event of an error
	var printables = ['print_CalcMethod','print_Age','print_Gender','print_Ethnicity',
					'print_Smoker','print_Diabetes','print_SystolicBP', 'print_OnBpTreatment', 
					'print_TotalCholesterol', 'print_HdlCholesterol', 'print_EarlyFH', 'print_CKD', 'print_AFib',
					'print_RA', 'print_BMI'];
	for (i=0; i<printables.length; i++) {
		$('#'+printables[i]).html('N/A');
	}

	var OVERESTIMATE = ($('#overestimate').val() *1) + 100; // Results in a number 100 to 175, eventually multiplied by a decimal (eg, 0.05) to describe a risk in percent (0.05 -> 5%)
	
	var BENE = benefit(formula_id);
	$('#benefit').text(BENE+'%');
	
	var TIME = $('#time').val() *1;
	var IS_MALE = gender();
	var AGE = $('#age').val() *1;
	var BLOODP = systole();
	var SMOKE = smoker();
	var TCHOL = totalchol();
	var HDLCHOL = hdlchol();
	var DIABETES = diabetes();
	var IVH = 0;
	
	// baseline values
	var BLOODP_A = 120;
	var SMOKE_A = 0;
	var TCHOL_A = 3;
	var HDLCHOL_A = 1.3;
	var DIABETES_A = 0;
	var IVH_A = 0;
	
	// formulas
	var badFormula = 0;
	var badFormula_NonSmoker = 0;
	var badFormulaBaseline = 0;
	
	// Reset some of the alerts
	$('.errorAlert').hide();
	$('#outcome').removeClass('opacity10');
	
    // Run through the visible textbox fields (looking for invalid entries)
	var minmax_error = false;
	$('input[type="number"]:visible').each( function () {
		var val = parseFloat($(this).val());
	    var min = parseFloat($(this).attr('min'));
	    var max = parseFloat($(this).attr('max'));
	
		// Special circumstance: allow height/weight textboxes to be zero (for BMI)
		var allowZero = ['height_cm', 'height_cm_label', 'height_in', 'height_in_label', 'weight_kg', 'weight_kg_label', 'weight_lbs', 'weight_lbs_label'];
		var allowZeroIndex = $.inArray($(this).attr('id'), allowZero);
		if (allowZeroIndex != -1) {
			// Only check max (don't check min/zero)
			if ((val > max) || (!isNumeric(val))) {
				$(this).change();   //Calling the 'change' event will force a check
				minmax_error = true;
			}
		} else {
			// Check min/max
			if ((val < min) || (val > max) || (!isNumeric(val))) {
				$(this).change();   //Calling the 'change' event will force a check
				minmax_error = true;
			}
		}
	});
	if (minmax_error) { return; }

	// CVD
	if ('cvd' == formula_id) {
		badFormula = OVERESTIMATE*calc_cvd(TIME, IS_MALE, AGE, BLOODP, SMOKE, TCHOL, HDLCHOL, DIABETES, IVH);
		badFormula_NonSmoker = OVERESTIMATE*calc_cvd(TIME, IS_MALE, AGE, BLOODP, SMOKE_A, TCHOL, HDLCHOL, DIABETES, IVH);
		badFormulaBaseline = OVERESTIMATE*calc_cvd(TIME, IS_MALE, AGE, BLOODP_A, SMOKE_A, TCHOL_A, HDLCHOL_A, DIABETES_A, IVH_A);
	}
	
	// CHD
	/*
	 *  NOTE: If these equations are ever re-used, they need to be converted into a function in order to support "smoking cessation" as a beneneficial treatment
	 *
	 *
	 
	else if ('chd' == formula_id) {
		badFormula = OVERESTIMATE*(1-Math.exp(-Math.exp((Math.log(TIME)-(15.5305+(28.4441*(1-IS_MALE))+(-1.4792*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-14.4588*Math.log(AGE)*(1-IS_MALE))+(1.8515*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.9119*Math.log(BLOODP))+(-0.2767*SMOKE)+(-0.7181*Math.log(TCHOL/HDLCHOL))+(-0.1759*DIABETES)+(-0.1999*DIABETES*(1-IS_MALE))+(-0.5865*IVH)+(0*IVH*IS_MALE)))/(Math.exp(0.9145)*Math.exp(-0.2784*(15.5305+(28.4441*(1-IS_MALE))+(-1.4792*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-14.4588*Math.log(AGE)*(1-IS_MALE))+(1.8515*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.9119*Math.log(BLOODP))+(-0.2767*SMOKE)+(-0.7181*Math.log(TCHOL/HDLCHOL))+(-0.1759*DIABETES)+(-0.1999*DIABETES*(1-IS_MALE))+(-0.5865*IVH)+(0*IVH*IS_MALE)))))));
		badFormulaBaseline = OVERESTIMATE*(1-Math.exp(-Math.exp((Math.log(TIME)-(15.5305+(28.4441*(1-IS_MALE))+(-1.4792*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-14.4588*Math.log(AGE)*(1-IS_MALE))+(1.8515*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.9119*Math.log(BLOODP_A))+(-0.2767*SMOKE_A)+(-0.7181*Math.log(TCHOL_A/HDLCHOL_A))+(-0.1759*DIABETES_A)+(-0.1999*DIABETES_A*(1-IS_MALE))+(-0.5865*IVH_A)+(0*IVH_A*IS_MALE)))/(Math.exp(0.9145)*Math.exp(-0.2784*(15.5305+(28.4441*(1-IS_MALE))+(-1.4792*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-14.4588*Math.log(AGE)*(1-IS_MALE))+(1.8515*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.9119*Math.log(BLOODP_A))+(-0.2767*SMOKE_A)+(-0.7181*Math.log(TCHOL_A/HDLCHOL_A))+(-0.1759*DIABETES_A)+(-0.1999*DIABETES_A*(1-IS_MALE))+(-0.5865*IVH_A)+(0*IVH_A*IS_MALE)))))));
	}
	
	// MI
	else if ('mi' == formula_id) {
		badFormula = OVERESTIMATE*(1-Math.exp(-Math.exp((Math.log(TIME)-(11.4712+(10.5109*(1-IS_MALE))+(-0.7965*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-5.4216*Math.log(AGE)*(1-IS_MALE))+(0.7101*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.6623*Math.log(BLOODP))+(-0.2675*SMOKE)+(-0.4277*Math.log(TCHOL/HDLCHOL))+(-0.1534*DIABETES)+(-0.1165*DIABETES*(1-IS_MALE))+(0*IVH)+(-0.1588*IVH*IS_MALE)))/(Math.exp(3.4064)*Math.exp(-0.8584*(11.4712+(10.5109*(1-IS_MALE))+(-0.7965*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-5.4216*Math.log(AGE)*(1-IS_MALE))+(0.7101*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.6623*Math.log(BLOODP))+(-0.2675*SMOKE)+(-0.4277*Math.log(TCHOL/HDLCHOL))+(-0.1534*DIABETES)+(-0.1165*DIABETES*(1-IS_MALE))+(0*IVH)+(-0.1588*IVH*IS_MALE)))))));
		badFormulaBaseline = OVERESTIMATE*(1-Math.exp(-Math.exp((Math.log(TIME)-(11.4712+(10.5109*(1-IS_MALE))+(-0.7965*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-5.4216*Math.log(AGE)*(1-IS_MALE))+(0.7101*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.6623*Math.log(BLOODP_A))+(-0.2675*SMOKE_A)+(-0.4277*Math.log(TCHOL_A/HDLCHOL_A))+(-0.1534*DIABETES_A)+(-0.1165*DIABETES_A*(1-IS_MALE))+(0*IVH_A)+(-0.1588*IVH_A*IS_MALE)))/(Math.exp(3.4064)*Math.exp(-0.8584*(11.4712+(10.5109*(1-IS_MALE))+(-0.7965*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(-5.4216*Math.log(AGE)*(1-IS_MALE))+(0.7101*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-0.6623*Math.log(BLOODP_A))+(-0.2675*SMOKE_A)+(-0.4277*Math.log(TCHOL_A/HDLCHOL_A))+(-0.1534*DIABETES_A)+(-0.1165*DIABETES_A*(1-IS_MALE))+(0*IVH_A)+(-0.1588*IVH_A*IS_MALE)))))));
	}
	
	// Stroke
	else if ('stroke' == formula_id) {
		badFormula = OVERESTIMATE*(1-Math.exp(-Math.exp((Math.log(TIME)-(26.5116+(0.2019*(1-IS_MALE))+(-2.3741*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(0*Math.log(AGE)*(1-IS_MALE))+(0*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-2.4643*Math.log(BLOODP))+(-0.3914*SMOKE)+(-0.0229*Math.log(TCHOL/HDLCHOL))+(-0.3087*DIABETES)+(-0.2627*DIABETES*(1-IS_MALE))+(-0.2355*IVH)+(0*IVH*IS_MALE)))/(Math.exp(-0.4312)*Math.exp(0*(26.5116+(0.2019*(1-IS_MALE))+(-2.3741*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(0*Math.log(AGE)*(1-IS_MALE))+(0*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-2.4643*Math.log(BLOODP))+(-0.3914*SMOKE)+(-0.0229*Math.log(TCHOL/HDLCHOL))+(-0.3087*DIABETES)+(-0.2627*DIABETES*(1-IS_MALE))+(-0.2355*IVH)+(0*IVH*IS_MALE)))))));
		badFormulaBaseline = OVERESTIMATE*(1-Math.exp(-Math.exp((Math.log(TIME)-(26.5116+(0.2019*(1-IS_MALE))+(-2.3741*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(0*Math.log(AGE)*(1-IS_MALE))+(0*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-2.4643*Math.log(BLOODP_A))+(-0.3914*SMOKE_A)+(-0.0229*Math.log(TCHOL_A/HDLCHOL_A))+(-0.3087*DIABETES_A)+(-0.2627*DIABETES_A*(1-IS_MALE))+(-0.2355*IVH_A)+(0*IVH_A*IS_MALE)))/(Math.exp(-0.4312)*Math.exp(0*(26.5116+(0.2019*(1-IS_MALE))+(-2.3741*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(0*Math.log(AGE)*(1-IS_MALE))+(0*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-2.4643*Math.log(BLOODP_A))+(-0.3914*SMOKE_A)+(-0.0229*Math.log(TCHOL_A/HDLCHOL_A))+(-0.3087*DIABETES_A)+(-0.2627*DIABETES_A*(1-IS_MALE))+(-0.2355*IVH_A)+(0*IVH_A*IS_MALE)))))));
	}
	*/
	
	else if ('framingham2008' == formula_id) {
	
		badFormula = OVERESTIMATE*Framingham2008(IS_MALE, AGE, BLOODP,  bptreatment(), SMOKE, Math.round(TCHOL/0.0259), Math.round(HDLCHOL/0.0259), DIABETES);
		badFormula_NonSmoker = OVERESTIMATE*Framingham2008(IS_MALE, AGE, BLOODP, bptreatment(), SMOKE_A, Math.round(TCHOL/0.0259), Math.round(HDLCHOL/0.0259), DIABETES);
		badFormulaBaseline = OVERESTIMATE*Framingham2008(IS_MALE, AGE, BLOODP_A, 0, 0, Math.round(TCHOL/0.0259), Math.round(HDLCHOL/0.0259), 0);
		
	}
	
	// ASCVD
	else if ('ascvd' == formula_id) {
		var IS_BLACK = black();
		var BPTREATMENT = bptreatment();
	
		// Select the appropriate sex/race
		var coeff;
		if ((IS_MALE) && (!IS_BLACK)) { coeff = new WhiteMale(); }
		if ((!IS_MALE) && (!IS_BLACK)) { coeff = new WhiteFemale(); }
		if ((IS_MALE) && (IS_BLACK)) { coeff = new BlackMale(); }
		if ((!IS_MALE) && (IS_BLACK)) { coeff = new BlackFemale(); }
		
		badFormula = OVERESTIMATE*ASCVD10YrRisk(coeff, AGE, Math.round(TCHOL/0.0259), Math.round(HDLCHOL/0.0259), BLOODP, BPTREATMENT, DIABETES, SMOKE);
		badFormula_NonSmoker = OVERESTIMATE*ASCVD10YrRisk(coeff, AGE, Math.round(TCHOL/0.0259), Math.round(HDLCHOL/0.0259), BLOODP, BPTREATMENT, DIABETES, 0);
		badFormulaBaseline = OVERESTIMATE*ASCVD10YrRisk(coeff, AGE, Math.round(TCHOL_A/0.0259), Math.round(HDLCHOL_A/0.0259), BLOODP_A, 0, 0, 0);
	}
	
	// QRISK
	else if ('qrisk' == formula_id) {
		// Note: I have preserved the variable names from the original C code to make future editing efforts easier.  The QRISK formula is updated yearly
		
		var age = AGE;
		var b_AF = afib();
		var b_ra = ra();
		var b_renal = ckd();
		var b_treatedhyp = bptreatment();
		var b_type1 = ($('#dm_cat').val() == '1' ? 1 : 0);
		var b_type2 = ($('#dm_cat').val() == '2' ? 1 : 0);
		var bmi = bodymassindex();
		var ethrisk = $('#ethnicity').val();
		var fh_cvd = famhistory();
		var rati = totalchol() / hdlchol();
		var sbp = systole();
		var smoke_cat = $('#smoke_cat').val();
		var surv = 10;	//	"surv must be 10" -- may be a placeholder for the future?
		var town = 0;	//	"We include the University of Nottingham "Postcode to Townsend" deprivation table, which means a patient's deprivation can be estimated by their postcode."

	    // Fill in the BMI for the user ...
		if (bmi == 0) {
			(IS_MALE) ? $('#bmi').html("25 kg/m<sup>2</sup> (imputed)") : $('#bmi').html("25 kg/m<sup>2</sup> (imputed)");
		} else {
			$('#bmi').html(bmi.toFixed(1) + " kg/m<sup>2</sup>");
		}
		
		// Function arguments: (age,b_AF,b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town)
		if (IS_MALE) {
			// QRISK multiplies by 100 within the function (to make a percentage).  We do this with OVERESTIMATE throughout this function.  I decided to divide by 100 (here) for QRISK to maintain the format of the QRISK code
			badFormula = OVERESTIMATE*QRISK_Male(age, b_AF, b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town)/100;
			badFormula_NonSmoker = OVERESTIMATE*QRISK_Male(age, b_AF, b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,0,surv,town)/100;
			badFormulaBaseline = OVERESTIMATE*QRISK_Male(age, b_AF, b_ra,b_renal,0,0,0,25.0,ethrisk,fh_cvd,(TCHOL_A/HDLCHOL_A),BLOODP_A,0,surv,town)/100;
		} else {
			badFormula = OVERESTIMATE*QRISK_Female(age, b_AF, b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town)/100;
			badFormula_NonSmoker = OVERESTIMATE*QRISK_Female(age, b_AF, b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,0,surv,town)/100;
			badFormulaBaseline = OVERESTIMATE*QRISK_Female(age, b_AF, b_ra,b_renal,0,0,0,25.0,ethrisk,fh_cvd,(TCHOL_A/HDLCHOL_A),BLOODP_A,0,surv,town)/100;
		}
	}
	
	// PREDICT
	else if ('predict' == formula_id) {
		//IS_MALE
		var age = AGE;
		var fh_cvd = famhistory();
		var b_treatedhyp = bptreatment();
		var b_treatedlipid = lipidtreatment();
		var b_treatedapac = apactreatment();
		var sbp = systole();
		//DIABETES
		var smoke_cat = $('#smoke_cat_trichotomous').val();
		var rati = totalchol() / hdlchol();
		var b_AF = afib();
		var deprivation = $('#deprivation_quintile').val();
		var ethrisk = $('#ethnicity_PREDICT').val();
		
		if (ckd()) {
			$('#alert_ckd').show();
		}
		
		//Function args: (sex,age,FH,tx_htn,tx_lipids,tx_apac,sbp,dm,smoker,tchdl_ratio,afib,deprivation,ethnicity)
		var risk = PREDICT(IS_MALE,age,fh_cvd,b_treatedhyp,b_treatedlipid,b_treatedapac,sbp,DIABETES,smoke_cat,rati,b_AF,deprivation,ethrisk);
		badFormula = OVERESTIMATE*risk/100;
		badFormula_NonSmoker = OVERESTIMATE*PREDICT(IS_MALE,age,fh_cvd,b_treatedhyp,b_treatedlipid,b_treatedapac,sbp,DIABETES,0,rati,b_AF,deprivation,ethrisk)/100;
		badFormulaBaseline = OVERESTIMATE*PREDICT(IS_MALE,age,fh_cvd,b_treatedhyp,b_treatedlipid,b_treatedapac,BLOODP_A,0,0,rati,b_AF,1,ethrisk)/100;	// BLOODP_A=120, Diabetes=0, Smoker=0,Deprivation=1
	}
	
	// Don't let optimal risk exceed patient's risk
	if (badFormula < badFormulaBaseline) { badFormulaBaseline = badFormula; }
	
	// Don't let the risk exceed 100% (only possible if family history [OVERESTIMATE] is implemented with a very high CVD risk)
	if (badFormula > 100) { badFormula = 100; }
	if (badFormula_NonSmoker > 100) {badFormula_NonSmoker = 100; }
	if (badFormulaBaseline>100) {badFormulaBaseline = 100; }
	
	// round off nearest 10th to prevent very large NNTs
	badFormula = Math.round(badFormula*10)/10;
	badFormula_NonSmoker = Math.round(badFormula_NonSmoker*10)/10;
	badFormulaBaseline = Math.round(badFormulaBaseline*10)/10;			// red faces
	
	// calculate
	var my_benefit;
	if ('smoking' == returnBenefitName(formula_id)) {
		// Benefit calculation for smoking cessation
		if (!smoker()) {
			BENE = 0;
			$('#benefit').text(LocalizeText("NA",language));
			my_benefit = 0;
		} else {
			my_benefit = Math.max(0, Math.round((badFormula - badFormula_NonSmoker)*10)/10);
			$('#benefit').text(LocalizeText("Variable",language));
		}
	} else {
		// Benefit not related to smoking status
		my_benefit = Math.max(0, (badFormula * BENE / 100));			// green faces
	}
	
	var additional = Math.max(0, (badFormula - badFormulaBaseline));	// pink faces
	var numSadFaces = Math.round(badFormulaBaseline); // red faces
	var numAddFaces = Math.round(additional); // pink faces
	
	// Subtract away the benefit ...
	var benefit_remaining = my_benefit;
	if ((additional > 0) && (benefit_remaining > 0)) {
		var subtract = Math.min(additional, benefit_remaining);
		additional = additional - subtract;
		benefit_remaining = benefit_remaining - subtract;
	}
	if ((badFormulaBaseline > 0) && (benefit_remaining > 0)) {
		var subtract = Math.min(badFormulaBaseline, benefit_remaining);
		badFormulaBaseline = badFormulaBaseline - subtract;
		benefit_remaining = benefit_remaining - subtract;
	}
	
	// The difference between our old/new red and pink faces will equal our green faces
	var numProFaces = 0;	// green faces
	if (numSadFaces != Math.round(badFormulaBaseline)) {
		numProFaces += Math.max(0,numSadFaces - Math.round(badFormulaBaseline));
		numSadFaces -= Math.max(0,numSadFaces - Math.round(badFormulaBaseline));
	}
	if (numAddFaces != Math.round(additional)) {
		numProFaces += Math.max(0,numAddFaces - Math.round(additional));
		numAddFaces -= Math.max(0,numAddFaces - Math.round(additional));
	}
	
	var totalSum = 100 - (numSadFaces + numAddFaces + numProFaces); // blue faces
	var good = 100 - (badFormulaBaseline + my_benefit + additional);	// blue faces
	
	// risk percentages
	$("#score_good").text(LocalizeDecimal(good.toFixed(1),language) + "%");	// blue faces
	$("#score_bad_sum").text(LocalizeDecimal((parseFloat(badFormulaBaseline.toFixed(1))+parseFloat(additional.toFixed(1))).toFixed(1),language) + "%");		//Because of rounding, using badFormula.toFixed(1) may not add up to the baseline + additional
	$("#score_bad").text(LocalizeDecimal(badFormulaBaseline.toFixed(1),language) + "%");
	$("#score_bad_add").text(LocalizeDecimal(additional.toFixed(1),language) + "%");
	$("#score_benefits").text(LocalizeDecimal(my_benefit.toFixed(1),language) + "%");
	$("#score_nnt").html(my_benefit > 0 ? Math.round(100 / my_benefit) : "&infin;");	//.html instead of .text for HTML entity (infinity)
	
	// add the faces
	var faces = $("#faces").empty();
	
	for (var i = 0; i < numSadFaces; i++) {
		faces.prepend(newFace('bad'));
	}
	for (var i = 0; i < numAddFaces; i++) {
		if (BasicView()) {
			faces.prepend(newFace('bad'));
		} else {
			faces.prepend(newFace('badA'));
		}
	}
	for (var i = 0; i < numProFaces; i++) {
		faces.prepend(newFace('green'));
	}
	for (var i = 0; i < totalSum; i++) {
		faces.prepend(newFace('blue'));
	}
	
	// Prepare our printable screen
	if (formula_id == 'framingham2008') { $('#print_CalcMethod').html('Framingham'); }
	if (formula_id == 'qrisk') { $('#print_CalcMethod').html('QRISK<sup>&reg;</sup>2-2014'); }
	if (formula_id == 'ascvd') { $('#print_CalcMethod').html('ACC/AHA ASCVD'); }
	if (formula_id == 'predict') { $('#print_CalcMethod').html('PREDICT'); }
	
	$('#print_Age').html(AGE + ' ' + LocalizeText('years',language));
	$('#print_Gender').html(IS_MALE ? LocalizeText('Male',language) : LocalizeText('Female',language));
	$('#print_CKD').html(ckd() ? LocalizeText('Yes',language) : LocalizeText('No',language));
	
	if (formula_id == 'qrisk') {
		//find(':selected').text() values are already localized
		$('#print_Smoker').html($('#smoke_cat').find(':selected').text());
		$('#print_Diabetes').html($('#dm_cat').find(':selected').text());
	} else {
		$('#print_Smoker').html($('#smoker_yes').hasClass('active') ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_Diabetes').html($('#diabetes_yes').hasClass('active') ? LocalizeText('Yes',language) : LocalizeText('No',language));
	}
	
	$('#print_SystolicBP').html(BLOODP);
	$('#print_OnBpTreatment').html(bptreatment() ? LocalizeText('Yes',language) : LocalizeText('No',language));
	
	if (_useMMOL) {
		$('#print_TotalCholesterol').html(LocalizeDecimal($('#totalchol_mmol').val(),language) + ' mmol/L');
		$('#print_HdlCholesterol').html(LocalizeDecimal($('#hdlchol_mmol').val(),language) + ' mmol/L');		
	} else {
		$('#print_TotalCholesterol').html(LocalizeDecimal($('#totalchol_mgdl').val(),language) + ' mg/dL');
		$('#print_HdlCholesterol').html(LocalizeDecimal($('#hdlchol_mgdl').val(),language) + ' mg/dL');		
	
	}
	
	// Set some defaults just in case...
	// Just in case ...
	$('#print_AFib').html(LocalizeText('NA',language));
	$('#print_RA').html(LocalizeText('NA',language));
	$('#print_BMI').html(LocalizeText('NA',language));
	$('#print_EarlyFH').html($('#overestimate').val() + '% ' + LocalizeText('AdditionalRisk',language));
	$('#print_Ethnicity').html(LocalizeText('NA',language));
	
	// By default, hide all 'restricted' class, then selectively show if necessary
	$('#print_DataPoints .restricted').hide();
	if (formula_id == 'qrisk') {
		$('.restricted.qrisk').show();
		$('#print_Ethnicity').html($('#ethnicity').find(':selected').text());	// Already localized
		$('#print_AFib').html(afib() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_RA').html(ra() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_BMI').html($('#bmi').html());
		$('#print_EarlyFH').html(famhistory() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		
	} else if (formula_id == 'ascvd') {
		$('.restricted.ascvd').show();
		$('#print_Ethnicity').html(IS_BLACK ? LocalizeText('Black',language) : LocalizeText('Non-Black',language));
		
	} else if (formula_id == 'predict') {
		$('.restricted.predict').show();
		$('#print_Smoker').html($('#smoke_cat_trichotomous').find(':selected').text());	// Already localized
		$('#print_Ethnicity').html($('#ethnicity_PREDICT').find(':selected').text());	// Already localized
		$('#print_OnLipidTreatment').html(lipidtreatment() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_OnAntithromboticTreatment').html(apactreatment() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_EarlyFH').html(famhistory() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_AFib').html(afib() ? LocalizeText('Yes',language) : LocalizeText('No',language));
		$('#print_DeprivationQuintile').html($('#deprivation_quintile').find(':selected').text());
	}
	
	if ($('#benefit_estimates .active').length > 0) {
		$('#print_DataPoints .benefit').show();
		$('#print_benefit').html($('#benefit_estimates .active').text() + ', ' + $('.relativeBenefit').text());	// Already localized
		
		var bene = $('#benefit_estimates .active').data('benefit');
		var res = _benefit_risks[bene];	// Already localized
		var harms = '';
		if ('string' == typeof(res)) {
			harms = res;
		}
		else if (res && res.length > 0) {
			harms = "<ul><li>" + res.join("</li><li>") + "</li></ul>";
		}
		if (harms.indexOf('<br><h3>') > 0) {	// "Additional benefits" will not be included in printout
			harms = harms.substring(0,harms.indexOf('<br><h3>'));	// Remove any 'additional benefits'
		}
		
		if (harms.length > 0) {
			$('#print_benefit_harms_li').show();
			$('#print_benefit_harms_label').html($('#benefit_estimates .active').text() + ', ' + LocalizeText('HarmOfIntervention',language));
			$('#print_benefit_harms').html(harms);
		} else {
			$('#print_benefit_harms_li').hide();	
			$('#print_benefit_harms').html('');
		}
		
	} else {
		// No benefit has been selected
		$('#print_DataPoints .benefit').hide();
		// Just in case...
		$('#print_benefit').html(LocalizeText('NA',language));
	}
}

function calc_cvd(TIME, IS_MALE, AGE, BLOODP, SMOKE, TCHOL, HDLCHOL, DIABETES, IVH) {
 return (1-Math.exp(-Math.exp((Math.log(TIME)-(18.8144+(-1.2146*(1-IS_MALE))+(-1.8443*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(0.3668*Math.log(AGE)*(1-IS_MALE))+(0*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-1.4032*Math.log(BLOODP))+(-0.3899*SMOKE)+(-0.539*Math.log(TCHOL/HDLCHOL))+(-0.3036*DIABETES)+(-0.1697*DIABETES*(1-IS_MALE))+(-0.3362*IVH)+(0*IVH*IS_MALE)))/(Math.exp(0.6536)*Math.exp(-0.2402*(18.8144+(-1.2146*(1-IS_MALE))+(-1.8443*Math.log(AGE))+(0*Math.log(AGE)*Math.log(AGE))+(0.3668*Math.log(AGE)*(1-IS_MALE))+(0*Math.log(AGE)*Math.log(AGE)*(1-IS_MALE))+(-1.4032*Math.log(BLOODP))+(-0.3899*SMOKE)+(-0.539*Math.log(TCHOL/HDLCHOL))+(-0.3036*DIABETES)+(-0.1697*DIABETES*(1-IS_MALE))+(-0.3362*IVH)+(0*IVH*IS_MALE)))))));
}

function Framingham2008(IsMale, Age, SBP, BpTreat, Smoker, TotalChol, HDL, DM) {

	// Validate ... Most of these are not applicable because the calculator uses slider values with mins/maxes, but this is a good double check in case the user interface changes in the future ...	
	var error = 0;
	if ((Age<30) || (Age>74)) {
		$('#alert_age').html(LocalizeText('Framingham2008AgeWarning',language)).show();
		error=1;
	}
	if ((SBP < 90) || (SBP > 200)) {
		$('#alert_sbp').html(LocalizeText('Framingham2008BpWarning',language)).show();
		error=1;
	}
	if ((HDL < 10) || (HDL> 100)) {
		$('#alert_hdl').html(LocalizeText('Framingham2008HdlWarning',language)).show();
		error=1;
	}
	if ((TotalChol < 100) || (TotalChol> 405)) {
		$('#alert_tchol').html(LocalizeText('Framingham2008TCWarning',language)).show();
		error=1;
	}
	if (error) { // Display all possible error messages before returning zero
		$('#outcome').addClass('opacity10');
		return 0;
	}


	var sum = 0;
	var base = 0;
	var constant = 0;
	
	if (IsMale) {
		base = 0.88936;
		constant = 23.9802;
		
		sum += Math.log(Age) * 3.06117;
		sum += Math.log(TotalChol) * 1.12370;
		sum += Math.log(HDL) * -0.93263;
		if (BpTreat == 1) {
			sum += Math.log(SBP) * 1.99881;
		} else {
			sum += Math.log(SBP) * 1.93303;
		}
		
		sum += Smoker * 0.65451;
		sum += DM * 0.57367;
	} else {
		// Female
		base = 0.95012;
		constant = 26.1931;
		
		sum += Math.log(Age) * 2.32888;
		sum += Math.log(TotalChol) * 1.20904;
		sum += Math.log(HDL) * -0.70833;
		if (BpTreat == 1) {
			sum += Math.log(SBP) * 2.82263;
		} else {
			sum += Math.log(SBP) * 2.76157;
		}
		
		sum += Smoker * 0.52873;
		sum += DM * 0.69154;
	}
	
	return 1 - Math.pow(base, Math.pow(Math.E, sum - constant));
}

function ASCVD10YrRisk(coeff, age, TC, HDL, SBP, BPTreatment, DM, Smoker) {
	var sum = 0;
	sum += Math.log(age) * coeff.Age;
	sum += Math.pow(Math.log(age), 2) * coeff.AgeSquared;
	sum += Math.log(TC) * coeff.TC;
	sum += Math.log(age) * Math.log(TC) * coeff.AgexTC;
	sum += Math.log(HDL) * coeff.HDL;
	sum += Math.log(age) * Math.log(HDL) * coeff.AgexHDL;

	if (BPTreatment === 1) {
		sum += Math.log(SBP) * coeff.TreatedBP;
		sum += Math.log(age) * Math.log(SBP) * coeff.AgexTreatedBP;
	} else {
		//No BP treatment
		sum += Math.log(SBP) * coeff.UntreatedBP;
		sum += Math.log(age) * Math.log(SBP) * coeff.AgexUntreatedBP;
	}

	sum += Smoker * coeff.Smoker;
	sum += Smoker * Math.log(age) * coeff.AgexSmoker;
	sum += DM * coeff.Diabetes;

	return 1 - Math.pow(coeff.BaselineSurvival, Math.pow(Math.E, sum - coeff.OverallMean));
}

function PREDICT(sex,age,FH,tx_htn,tx_lipids,tx_apac,sbp,dm,smoker,tchdl_ratio,afib,deprivation,ethnicity) {

	var sum = 0;
	
	if (sex == 1) {	//MALE
		// Coefficients
		sum += 0.0675532 *(age-51.79953);
		sum += 0.2899054*(ethnicity==2); //maori
		sum += 0.1774195*(ethnicity==3); //pacific
		sum += 0.2902049*(ethnicity==1); //indian
		sum += -0.3975687*(ethnicity==4); //chinese-other
		sum += 0.0794903*(deprivation-2.972793);
		sum += 0.0753246 *(smoker==1);
		sum += 0.5058041 *(smoker==2);
		sum += 0.1326587*(FH);
		sum += 0.5880131*(afib);
		sum += 0.5597023*(dm);
		sum += 0.0163778*(sbp-129.1095);
		sum += 0.1283758*(tchdl_ratio-4.38906);
		sum += 0.2947634*(tx_htn);
		sum += -0.0537314*(tx_lipids);
		sum += 0.0934141*(tx_apac);
		// Interactions
		sum += (age-52)*dm*-0.020235;
		sum += (sbp-129)*(age-52)*-0.0004184;
		sum += (sbp-129)*tx_htn*-0.0053077;

		return (1 - Math.pow(0.974755526232, Math.pow(Math.E, sum)))*100;
		
		
	} else {	// Female
		// Coefficients
		sum += 0.0756412 *(age-56.13665);
		sum += 0.3910183*(ethnicity==2); //maori
		sum += 0.2010224*(ethnicity==3); //pacific
		sum += 0.1183427*(ethnicity==1); //indian
		sum += -0.28551*(ethnicity==4); //chinese-other
		sum += 0.1080795*(deprivation-2.990826);
		sum += 0.087476 *(smoker==1);
		sum += 0.6226384 *(smoker==2);
		sum += 0.0445534*(FH);
		sum += 0.8927126*(afib);
		sum += 0.5447632*(dm);
		sum += 0.0136606*(sbp-129.0173);
		sum += 0.1226753*(tchdl_ratio-3.726268);
		sum += 0.339925*(tx_htn);
		sum += -0.0593798*(tx_lipids);
		sum += 0.1172496*(tx_apac);
		// Interactions
		sum += (age-56)*dm*-0.0222549;
		sum += (sbp-129)*(age-56)*-0.0004425;
		sum += (sbp-129)*tx_htn*-0.004313;

		return (1 - Math.pow(0.983169213058, Math.pow(Math.E, sum)))*100;
	}	
}

/* 
 * Copyright 2013 ClinRisk Ltd.
 * 
 * This file is part of QRISK2-2014 (http://qrisk.org, original sources at http://svn.clinrisk.co.uk/opensource/qrisk2).
 * 
 * QRISK2-2014 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QRISK2-2014 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QRISK2-2014.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Additional terms
 * 
 * The following disclaimer must be held together with any risk score score generated by this code.  If the score is displayed, then this disclaimer must be displayed or otherwise be made easily accessible, e.g. by a prominent link alongside it.
 *   The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qrisk2, faithfully implements QRISK2-2014.
 *   ClinRisk Ltd. have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 *   However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone accidentally 
 *   altering the coefficients, getting the inputs wrong, or just poor programming.
 *   ClinRisk Ltd. stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qrisk2.
 *   Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * End of additional terms
 */
 
 /*
Converted from http://svn.clinrisk.co.uk/opensource/qrisk2/c/Q80_model_4_1.c
 * XML source: Q80_model_4_0.xml
 * STATA dta time stamp: 24 Sep 2013 22:39
 * This file was created on: Mon  9 Dec 2013 17:58:53 GMT
*/
function QRISK_Male(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town) {
	// Impute BMI if necessary
	if (bmi == 0) {
		bmi = 25.0;
	}
	
	// Validate ... Most of these are not applicable because the calculator uses slider values with mins/maxes, but this is a good double check in case the user interface changes in the future ...	
	var error = 0;
	if ((age<25) || (age>84)) {
		$('#alert_age').html(LocalizeText('QriskAgeWarning',language)).show();
		error=1;
	}
	if (((bmi<20) || (bmi>40))) {
		$('#alert_BMI').html(LocalizeText('QriskBmiWarning',language)).show();
		error=1;
	}
	if ((sbp<70) || (sbp > 210)) {
		$('#alert_sbp').html(LocalizeText('QriskBpWarning',language)).show();
		error=1;
	}
	if ((rati < 1) || (rati > 12)) {
		$('#alert_chol').html(LocalizeText('QriskCholRatioWarning',language) + ' (' + Math.round(totalchol()/hdlchol()*10)/10 + ' ' + LocalizeText('entered',language) + ')').show();
		error=1;
	}
	if (error) { // Display all possible error messages before returning zero
		$('#outcome').addClass('opacity10');
		return 0;
	}
	
	var survivor = [
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0.977699398994446,
		0,
		0,
		0,
		0,
		0];
	
	/* The conditional arrays */
	var Iethrisk = [
		0,
		0,
		0.3567133647493443400000000,
		0.5369559608176189800000000,
		0.5190878419529624300000000,
		0.2182992106490147000000000,
		-0.3474174705898491800000000,
		-0.3674730037922803700000000,
		-0.3749664891426142700000000,
		-0.1926947742531604500000000
	];
	var Ismoke = [
		0,
		0.2784649664157046200000000,
		0.6067834395168959500000000,
		0.7103835060989258700000000,
		0.8626172339181202900000000
	];
	
	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */
	var dage = age;
	dage=dage/10;
	var age_1 = Math.pow(dage,-1);
	var age_2 = Math.pow(dage,2);
	var dbmi = bmi;
	dbmi=dbmi/10;
	var bmi_1 = Math.pow(dbmi,-2);
	var bmi_2 = Math.pow(dbmi,-2)*Math.log(dbmi);
	
	/* Centring the continuous variables */
	age_1 = age_1 - 0.232008963823318;
	age_2 = age_2 - 18.577636718750000;
	bmi_1 = bmi_1 - 0.146408438682556;
	bmi_2 = bmi_2 - 0.140651300549507;
	rati = rati - 4.377167701721191;
	sbp = sbp - 131.038314819335940;
	town = town - 0.151332527399063;

	/* Start of Sum */
	var a=0;

	/* The conditional sums */
	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */
	a += age_1 * -17.6225543381945610000000000;
	a += age_2 * 0.0241873189298273640000000;
	a += bmi_1 * 1.7320282704272665000000000;
	a += bmi_2 * -7.2311754066699754000000000;
	a += rati * 0.1751387974012235100000000;
	a += sbp * 0.0101676305179196900000000;
	a += town * 0.0298177271496720960000000;

	/* Sum from boolean values */
	a += b_AF * 0.9890997526189402300000000;
	a += b_ra * 0.2541886209118611200000000;
	a += b_renal * 0.7949789230438320000000000;
	a += b_treatedhyp * 0.6229359479868044100000000;
	a += b_type1 * 1.3330353321463930000000000;
	a += b_type2 * 0.9372956828151940400000000;
	a += fh_cvd * 0.5923353736582422900000000;

	/* Sum from interaction terms */
	a += age_1 * (smoke_cat==1) * 0.9243747443632776000000000;
	a += age_1 * (smoke_cat==2) * 1.9597527500081284000000000;
	a += age_1 * (smoke_cat==3) * 2.9993544847631153000000000;
	a += age_1 * (smoke_cat==4) * 5.0370735254768100000000000;
	a += age_1 * b_AF * 8.2354205455482727000000000;
	a += age_1 * b_renal * -3.9747389951976779000000000;
	a += age_1 * b_treatedhyp * 7.8737743159167728000000000;
	a += age_1 * b_type1 * 5.4238504414460937000000000;
	a += age_1 * b_type2 * 5.0624161806530141000000000;
	a += age_1 * bmi_1 * 33.5437525167394240000000000;
	a += age_1 * bmi_2 * -129.9766738257203800000000000;
	a += age_1 * fh_cvd * 1.9279963874659789000000000;
	a += age_1 * sbp * 0.0523440892175620200000000;
	a += age_1 * town * -0.1730588074963540200000000;
	a += age_2 * (smoke_cat==1) * -0.0034466074038854394000000;
	a += age_2 * (smoke_cat==2) * -0.0050703431499952954000000;
	a += age_2 * (smoke_cat==3) * 0.0003216059799916440800000;
	a += age_2 * (smoke_cat==4) * 0.0031312537144240087000000;
	a += age_2 * b_AF * 0.0073291937255039966000000;
	a += age_2 * b_renal * -0.0261557073286531780000000;
	a += age_2 * b_treatedhyp * 0.0085556382622618121000000;
	a += age_2 * b_type1 * 0.0020586479482670723000000;
	a += age_2 * b_type2 * -0.0002328590770854172900000;
	a += age_2 * bmi_1 * 0.0811847212080794990000000;
	a += age_2 * bmi_2 * -0.2558919068850948300000000;
	a += age_2 * fh_cvd * -0.0056729073729663406000000;
	a += age_2 * sbp * -0.0000536584257307299330000;
	a += age_2 * town * -0.0010763305052605857000000;

	/* Calculate the score itself */
	var score = 100.0 * (1 - Math.pow(survivor[surv], Math.exp(a)) );
	return score;
}

/*
Converted from http://svn.clinrisk.co.uk/opensource/qrisk2/c/Q80_model_4_0.c
 * XML source: Q80_model_4_0.xml
 * STATA dta time stamp: 24 Sep 2013 22:39
 * This file was created on: Mon  9 Dec 2013 17:58:53 GMT
*/
function QRISK_Female(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town) {
	// Impute BMI if necessary
	if (bmi == 0) {
		bmi = 25.0;
	}
	
	// Validate ... Most of these are not applicable because the calculator uses slider values with mins/maxes, but this is a good double check in case the user interface changes in the future ...	
	var error = 0;
	if ((age<25) || (age>84)) {
		$('#alert_age').html(LocalizeText('QriskAgeWarning',language)).show();
		error=1;
	}
	if (((bmi<20) || (bmi>40))) {
		$('#alert_BMI').html(LocalizeText('QriskBmiWarning',language)).show();
		error=1;
	}
	if ((sbp<70) || (sbp > 210)) {
		$('#alert_sbp').html(LocalizeText('QriskBpWarning',language)).show();
		error=1;
	}
	if ((rati < 1) || (rati > 12)) {
		$('#alert_chol').html(LocalizeText('QriskCholRatioWarning',language) + ' (' + Math.round(totalchol()/hdlchol()*10)/10 + ' ' + LocalizeText('entered',language) + ')').show();
		error=1;
	}
	if (error) { // Display all possible error messages before returning zero
		$('#outcome').addClass('opacity10');
		return 0;
	}
	
	var survivor = [
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0.988948762416840,
		0,
		0,
		0,
		0,
		0
	];

	/* The conditional arrays */
	var Iethrisk = [
		0,
		0,
		0.2671958047902151500000000,
		0.7147534261793343500000000,
		0.3702894474455115700000000,
		0.2073797362620235500000000,
		-0.1744149722741736900000000,
		-0.3271878654368842200000000,
		-0.2200617876129250500000000,
		-0.2090388032466696800000000
	];
	var Ismoke = [
		0,
		0.1947480856528854800000000,
		0.6229400520450627500000000,
		0.7405819891143352600000000,
		0.9134392684576959600000000
	];

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */
	var dage = age;
	dage=dage/10;
	var age_1 = Math.pow(dage,.5);
	var age_2 = dage;
	var dbmi = bmi;
	dbmi=dbmi/10;
	var bmi_1 = Math.pow(dbmi,-2);
	var bmi_2 = Math.pow(dbmi,-2)*Math.log(dbmi);

	/* Centring the continuous variables */
	age_1 = age_1 - 2.099778413772583;
	age_2 = age_2 - 4.409069538116455;
	bmi_1 = bmi_1 - 0.154046609997749;
	bmi_2 = bmi_2 - 0.144072100520134;
	rati = rati - 3.554229259490967;
	sbp = sbp - 125.773628234863280;
	town = town - 0.032508373260498;

	/* Start of Sum */
	var a=0;

	/* The conditional sums */
	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */
	a += age_1 * 3.8734583855051343000000000;
	a += age_2 * 0.1346634304478384600000000;
	a += bmi_1 * -0.1557872403333062600000000;
	a += bmi_2 * -3.7727795566691125000000000;
	a += rati * 0.1525695208919679600000000;
	a += sbp * 0.0132165300119653560000000;
	a += town * 0.0643647529864017080000000;

	/* Sum from boolean values */
	a += b_AF * 1.4235421148946676000000000;
	a += b_ra * 0.3021462511553648100000000;
	a += b_renal * 0.8614743039721416400000000;
	a += b_treatedhyp * 0.5889355458733703800000000;
	a += b_type1 * 1.6684783657502795000000000;
	a += b_type2 * 1.1350165062510138000000000;
	a += fh_cvd * 0.5133972775738673300000000;

	/* Sum from interaction terms */
	a += age_1 * (smoke_cat==1) * 0.6891139747579299000000000;
	a += age_1 * (smoke_cat==2) * 0.6942632802121626600000000;
	a += age_1 * (smoke_cat==3) * -1.6952388644218186000000000;
	a += age_1 * (smoke_cat==4) * -1.2150150940219255000000000;
	a += age_1 * b_AF * -3.5855215448190969000000000;
	a += age_1 * b_renal * -3.0766647922469192000000000;
	a += age_1 * b_treatedhyp * -4.0295302811880314000000000;
	a += age_1 * b_type1 * -0.3344110567405778600000000;
	a += age_1 * b_type2 * -3.3144806806620530000000000;
	a += age_1 * bmi_1 * -5.5933905797230006000000000;
	a += age_1 * bmi_2 * 64.3635572837688980000000000;
	a += age_1 * fh_cvd * 0.8605433761217157200000000;
	a += age_1 * sbp * -0.0509321154551188590000000;
	a += age_1 * town * 0.1518664540724453700000000;
	a += age_2 * (smoke_cat==1) * -0.1765395485882681500000000;
	a += age_2 * (smoke_cat==2) * -0.2323836483278573000000000;
	a += age_2 * (smoke_cat==3) * 0.2734395770551826300000000;
	a += age_2 * (smoke_cat==4) * 0.1432552287454152700000000;
	a += age_2 * b_AF * 0.4986871390807032200000000;
	a += age_2 * b_renal * 0.4393033615664938600000000;
	a += age_2 * b_treatedhyp * 0.6904385790303250200000000;
	a += age_2 * b_type1 * -0.1734316566060327700000000;
	a += age_2 * b_type2 * 0.4864930655867949500000000;
	a += age_2 * bmi_1 * 1.5223341309207974000000000;
	a += age_2 * bmi_2 * -12.7413436207964070000000000;
	a += age_2 * fh_cvd * -0.2756708481415109900000000;
	a += age_2 * sbp * 0.0073790750039744186000000;
	a += age_2 * town * -0.0487465462679640900000000;

	/* Calculate the score itself */
	var score = 100.0 * (1 - Math.pow(survivor[surv], Math.exp(a)) );
	return score;
}

// BP meds benefits are NOT being applied if BP is LOWER THAN this number
function AboveThresholdForBpMeds() {
	
	if (diabetes() || ckd()) {
		return (systole() >= 140);
	} else {
		return (systole() >= 130);
	}
}

/**
 *  Returns a smilie face image.
 */
function newFace(type) {
	var retina = false;
	if ('devicePixelRatio' in window) {
		retina = (window.devicePixelRatio > 1);
	}
	
	var img = new Image();
	img.src = "imgs/" + type + (retina ? '@2x' : '') + ".png";
	
	return img;
}


/**
 *  Changes the interface between using mmol/L and mg/dL.
 */
var _useMMOL = true;
function toggleCholesterolUnit() {
	_useMMOL = !_useMMOL;
	
	var factor = 38.666666;
	if (_useMMOL) {
		$('#input').find('.chol_mmol').show();
		$('#input').find('.chol_mgdl').hide();
		
		var total = Math.round($('#totalchol_mgdl').val() / factor * 10) / 10;		// increments by 0.1
		$('#totalchol_mmol').val(total);
		$('#chol_mmol').val(total);
		adjustSlider('chol_mmol', 'totalchol_mmol', _alerts['tchol'], null, true);
		
		var hdl = Math.round($('#hdlchol_mgdl').val() / factor * 10) / 10;
		$('#hdlchol_mmol').val(hdl);
		$('#hdl_mmol').val(hdl);
		adjustSlider('hdl_mmol', 'hdlchol_mmol', _alerts['hdl'], null, true);
	}
	else {
		$('#input').find('.chol_mmol').hide();
		$('#input').find('.chol_mgdl').show();
		
		var total = Math.round($('#totalchol_mmol').val() * factor / 2) * 2;		// increments by 2
		$('#totalchol_mgdl').val(total);
		$('#chol_mgdl').val(total);
		adjustSlider('chol_mgdl', 'totalchol_mgdl', _alerts['tchol'], null, true);
		
		var hdl = Math.round($('#hdlchol_mmol').val() * factor / 2) * 2;
		$('#hdlchol_mgdl').val(hdl);
		$('#hdl_mgdl').val(hdl);
		adjustSlider('hdl_mgdl', 'hdlchol_mgdl', _alerts['hdl'], null, true);
	}
	
	CALC();
}

var _useCm = true;
function toggleHeightUnit() {
	_useCm = !_useCm;
	var factor = 2.54;
	if (_useCm) {
		$('#divHeightCm').show();
		$('#divHeightIn').hide();
		
		var ht = Math.round($('#height_in').val() * factor * 2) / 2;	//increments by 2 cm
		$('#height_cm').val(ht);
		$('#height_cm_label').val(ht);
		adjustSlider('height_cm_label', 'height_cm', _alerts['height'], null, true);
	}
	else {
		$('#divHeightCm').hide();
		$('#divHeightIn').show();	
		
		var ht = Math.round($('#height_cm').val() / factor * 1) / 1;	//increments by 1 in
		$('#height_in').val(ht);
		$('#height_in_label').val(ht);
		adjustSlider('height_in_label', 'height_in', _alerts['height'], null, true);
	}
}

var _useKg = true;
function toggleWeightUnit() {
	_useKg = !_useKg;
	var factor = 2.2;
	if (_useKg) {
		$('#divWeightKg').show();
		$('#divWeightLbs').hide();
		
		var wt = Math.round($('#weight_lbs').val() / factor * 0.5) / 0.5;	//increments by 0.5 kg
		$('#weight_kg').val(wt);
		$('#weight_kg_label').val(wt);
		adjustSlider('weight_kg_label', 'weight_kg', _alerts['weight'], null, true);
	}
	else {
		$('#divWeightKg').hide();
		$('#divWeightLbs').show();	
		
		var wt = Math.round($('#weight_kg').val() * factor * 1) / 1;	//increments by 1 lb
		$('#weight_lbs').val(wt);
		$('#weight_lbs_label').val(wt);
		adjustSlider('weight_lbs_label', 'weight_lbs', _alerts['weight'], null, true);
	}
}


/**
 *  Shows the images for risk types.
 */
/*
function showImages(tab) {
	var content = "";
	
 	if ('cvd' == tab) {
 		content = '<div><img src="imgs/heart_attack.jpg" />Heart Attacks</div><div><img src="imgs/heart_failure.jpg" />Heart Failure</div><div><img src="imgs/stroke.jpg" />Strokes</div><div><img src="imgs/intermittent.jpg" />Intermittent claudication</div>';
 	}
 	else if ('chd' == tab) {
 		content = '<div><img src="imgs/heart_attack.jpg" />Heart Attacks</div><div><img src="imgs/angina.jpg" />Angina</div>';
 	}
 	else if ('mi' == tab) {
 		content = '<div><img src="imgs/heart_attack.jpg" />Heart Attacks</div>';
 	}
 	else if ('stroke' == tab) {
 		content = '<div><img src="imgs/stroke.jpg" />Strokes</div>';
 	}
 	
	$("#disease").html(content);
}
*/



/**
 *  Convert sliders on IE9 and lower.
 *  We don't target FireFox because we use html5slider.js and we don't care about old WebKit browsers.
 */
function convertSliders() {			
	$('input[type=range]').each(function(idx, obj) {
		$(obj)
		.keyup(function(e) {
			var slider = $(e.target);
			var min = 1*slider.attr('min2');
			var max = 1*slider.attr('max');
			var val = slider.val();
			
			// check bounds
			if (undefined !== min && val < min) {
				slider.val(min);
			}
			if (undefined !== max && val > max) {
				slider.val(max);
			}
			
			// calculate score
			CALC();
		})
		.css('width', '30%')
		.next('b').hide();
	});
}


function offlineHint() {
	alert(LocalizeText('OfflineInfo',language));
}

function offlineStatusChanged(event) {
	var text = LocalizeText('OfflineHint',language);
	if ('checking' == event.type || 'downloading' == event.type) {
		text = LocalizeText('Cache',language) + ' ' + event.type + "...";
	}
	else if ('updateready' == event.type) {
		window.applicationCache.swapCache();
		window.location.reload();
	}
	
	$('#cache_status').text(text);
}



/*
 *  Extending Array capabilities
 */

Array.prototype.contains = function(obj) {
	return (this.indexOf(obj) >= 0);
}

if ( ! ('indexOf' in Array.prototype)) {
	Array.prototype.indexOf = function(obj) {
		for(var i = 0; i < this.length; i++) {
			if (this[i] == obj)
				return i;
		}
		
		return -1;
	}
}
 