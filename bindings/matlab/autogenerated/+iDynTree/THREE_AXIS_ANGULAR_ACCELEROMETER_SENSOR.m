function v = THREE_AXIS_ANGULAR_ACCELEROMETER_SENSOR()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = iDynTreeMEX(0, 25);
  end
  v = vInitialized;
end