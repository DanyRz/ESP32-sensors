function Decoder(bytes, port) {
  

  var rawTempr = (bytes[0] << 8) | bytes[1];  
  var rawHumid = (bytes[2] << 8) | bytes[3];  
 
  // throw away high bits for repeatability.
  rawTempr &= 0xFFFF;
  rawHumid &= 0xFFFF;

  // special case minus zero:
  if (rawTempr == 0x8000) {
    return -0.0;
  }
  if (rawHumid == 0x8000) {
    return -0.0;
  }

  // extract the sign.
  var sSignTempr = ((rawTempr & 0x8000) != 0) ? -1 : 1;
  var sSignHumid = ((rawHumid & 0x8000) != 0) ? -1 : 1;

  // extract the exponent
  var exp1Tempr = (rawTempr >> 11) & 0xF;
  var exp1Humid = (rawHumid >> 11) & 0xF;

  // extract the "mantissa" (the fractional part)
  var mant1Tempr = (rawTempr & 0x7FF) / 2048.0;
  var mant1Humid = (rawHumid & 0x7FF) / 2048.0;

  // convert back to a floating point number. We hope
  // that Math.pow(2, k) is handled efficiently by
  // the JS interpreter! If this is time critical code,
  // you can replace by a suitable shift and divide.
  var f_unscaledTempr = sSignTempr * mant1Tempr * Math.pow(2, exp1Tempr - 15);
  var f_unscaledHumid = sSignHumid * mant1Humid * Math.pow(2, exp1Humid - 15);

  return {
     Temprature: f_unscaledTempr * 100,
     Humidity: f_unscaledHumid * 100,
  };
}
