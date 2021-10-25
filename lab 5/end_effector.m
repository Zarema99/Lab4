%Convert time to seconds
start_time = time(1)*ones(1, size(time, 1));
time1 = (time - start_time)*10^-9;
x = fielddata0;
y = fielddata1;
figure
plot(time1, x, 'r');
title('X position coordinates of end-effector vs time')
xlabel('Time (sec)')
ylabel('Position (metric units)')
figure 
plot(time1, y, 'b');
title('Y position coordinates of end-effector vs time')
xlabel('Time (sec)')
ylabel('Position (metric units)')
