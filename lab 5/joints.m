%Convert time to seconds
start_time = time(1)*ones(1, size(time, 1));
time1 = (time - start_time)*10^-9;
end_effector = fieldposition0;
joint2 = fieldposition1;
joint4 = fieldposition2;
joint6 = fieldposition3;
motortom2m = fieldposition4;
figure
plot(time1, end_effector, 'r', time1, joint2, 'b', time1, joint4, 'g', time1, joint6, 'y', time1, motortom2m, 'm');
title('Joint angles vs time')
xlabel('Time (sec)')
ylabel('Angular position (rad)')

