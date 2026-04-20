package com.example.mynative.alender;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import com.example.mynative.alender.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    private ActivityMainBinding binding;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        
        // Set text from native code
        binding.textView.setText(stringFromJNI());
    }
    
    @Override
    protected void onDestroy() {
        super.onDestroy();
        binding = null;
    }
    
    public native String stringFromJNI();
    
    static {
        // Used to load the 'myapplication' library on application startup.
        System.loadLibrary("blenderAndroid");
    }
}